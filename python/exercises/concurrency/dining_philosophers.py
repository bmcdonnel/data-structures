import random
import time

from multiprocessing import Process, Lock, Event

class Philosopher(Process):
    def __init__(self, name, left_fork, right_fork, stop_event):
        super().__init__()

        self.name = name
        self.left_fork = left_fork
        self.right_fork = right_fork
        self.stop_event = stop_event

    def _should_run(self):
        return not self.stop_event.is_set()

    def run(self):
        while self._should_run():
            time.sleep(random.uniform(1,10))

            print("{} is hungry".format(self.name))

            self.dine()

        print("{} is done".format(self.name))

    def dine(self):
        if not self._should_run():
            return

        fork1 = self.left_fork
        fork2 = self.right_fork

        while True:
            fork1.acquire(block=True)
            success = fork2.acquire(block=False)

            if success:
                break

            fork1.release()
            fork1, fork2 = fork2, fork1

        self._dining()
        fork2.release()
        fork1.release()

    def _dining(self):
        print("{} started eating".format(self.name))
        time.sleep(random.uniform(1,10))
        print("{} finished eating".format(self.name))

def main():
    stop_event = Event()
    forks = [Lock() for n in range(5)]
    philosopher_names = ['Descarte', 'Locke', 'Newton', 'Aristotle', 'Confucius']
    philosophers = [Philosopher(philosopher_names[i], forks[i], forks[(i+1) % 5], stop_event) for i in range(5)]

    random.seed(time.time())

    [p.start() for p in philosophers]

    time.sleep(10)

    print("Finishing up")

    stop_event.set()

    [p.join() for p in philosophers]

if __name__ == "__main__":
    main()
