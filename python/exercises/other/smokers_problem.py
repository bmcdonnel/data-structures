import random
import time

from multiprocessing import Process, Lock, Semaphore, Event, Value

class StoppableProcess(Process):
    def __init__(self, stop_event):
        super().__init__()

        self.stop_event = stop_event

    def _should_run(self):
        return not self.stop_event.is_set()

class Smoker(StoppableProcess):
    def __init__(
            self,
            name,
            agent,
            my_turn,
            stop_event):
        super().__init__(stop_event)

        self.name = name
        self.agent = agent
        self.my_turn = my_turn

    def run(self):
        while self._should_run():
            self.my_turn.acquire()

            print("{} smoking a cigarette".format(self.name))
            time.sleep(2)
            print("{} finished smoking".format(self.name))

            self.agent.release()

        print("{} smoker is done".format(self.name))

class Watcher(StoppableProcess):
    def __init__(
            self,
            name,
            ingredient1,
            ingredient2_smoker, 
            ingredient3_smoker,
            is_ingredient1,
            is_ingredient2,
            is_ingredient3,
            ingredient_state,
            stop_event):
        super().__init__(stop_event)

        self.name = name
        self.ingredient1 = ingredient1
        self.ingredient2_smoker = ingredient2_smoker
        self.ingredient3_smoker = ingredient3_smoker
        self.is_ingredient1 = is_ingredient1
        self.is_ingredient2 = is_ingredient2
        self.is_ingredient3 = is_ingredient3
        self.ingredient_state = ingredient_state

    def run(self):
        while self._should_run():
            self.ingredient1.acquire()

            self.ingredient_state.acquire()
            if self.is_ingredient2.value == 1:
                self.is_ingredient2.value = 0
                print("{} watcher triggering smoker 3".format(self.name))
                self.ingredient3_smoker.release()
            elif self.is_ingredient3.value == 1:
                self.is_ingredient3.value = 0
                print("{} watcher triggering smoker 2".format(self.name))
                self.ingredient2_smoker.release()
            else:
                self.is_ingredient1.value = 1
                print("{} watcher marking ingredient as available".format(self.name))
            self.ingredient_state.release()

        print("{} watcher is done".format(self.name))

class Agent(StoppableProcess):
    def __init__(
            self,
            agent_semaphore,
            tobacco_semaphore,
            paper_semaphore,
            match_semaphore,
            stop_event):
        super().__init__(stop_event)

        self.agent_semaphore = agent_semaphore
        self.ingredient_semaphores = (
            ("Tobacco", tobacco_semaphore),
            ("Paper", paper_semaphore),
            ("Match", match_semaphore)
        )

    def run(self):
        while self._should_run():
            self.agent_semaphore.acquire()

            tuple1, tuple2 = random.sample(self.ingredient_semaphores, 2)

            print("Agent selected {} and {}".format(tuple1[0], tuple2[0]))
            tuple1[1].release()
            tuple2[1].release()

        print("Agent is done")

def main():
    stop_event = Event()

    is_tobacco = Value('B', 0)
    is_paper = Value('B', 0)
    is_match = Value('B', 0)
    ingredient_state = Lock()

    agent_semaphore = Semaphore(1)
    tobacco_semaphore = Semaphore(0)
    paper_semaphore = Semaphore(0)
    match_semaphore = Semaphore(0)
    tobacco_smoker_semaphore = Semaphore(0)
    paper_smoker_semaphore = Semaphore(0)
    match_smoker_semaphore = Semaphore(0)

    tobacco_smoker = Smoker(
        "Tobacco",
        agent_semaphore,
        tobacco_smoker_semaphore,
        stop_event,
    )
    paper_smoker = Smoker(
        "Paper",
        agent_semaphore,
        paper_smoker_semaphore,
        stop_event,
    )
    match_smoker = Smoker(
        "Match",
        agent_semaphore,
        match_smoker_semaphore,
        stop_event,
    )

    watchers = [
        Watcher(
            "Tobacco", tobacco_semaphore,
            paper_smoker_semaphore, match_smoker_semaphore,
            is_tobacco, is_paper, is_match, ingredient_state,
            stop_event,
        ),
        Watcher(
            "Paper", paper_semaphore,
            match_smoker_semaphore, tobacco_smoker_semaphore,
            is_paper, is_match, is_tobacco, ingredient_state,
            stop_event,
        ),
        Watcher(
            "Match", match_semaphore,
            tobacco_smoker_semaphore, paper_smoker_semaphore,
            is_match, is_tobacco, is_paper, ingredient_state,
            stop_event,
        ),
    ]

    agent = Agent(
        agent_semaphore,
        tobacco_semaphore,
        paper_semaphore,
        match_semaphore,
        stop_event,
    )

    random.seed(time.time())

    tobacco_smoker.start()
    paper_smoker.start()
    match_smoker.start()
    [w.start() for w in watchers]
    agent.start()

    time.sleep(10)

    print("Finishing up")

    stop_event.set()

    agent.join()
    [w.join() for w in watchers]
    match_smoker.join()
    paper_smoker.join()
    tobacco_smoker.join()

if __name__ == "__main__":
    main()
