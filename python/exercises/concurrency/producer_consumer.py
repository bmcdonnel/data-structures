import random
import time

from exercises.common.stoppable_process import StoppableProcess
from multiprocessing import Process, Event, Queue

class Producer(StoppableProcess):
    def __init__(self, stop_event, producer_id, queue):
        super().__init__(stop_event)

        self.queue = queue
        self.id = producer_id

    def run(self):
        while self._should_run():
            time.sleep(random.uniform(1,5))
            print("Producer {} creating a task".format(self.id))
            self.queue.put("GO")

        self.queue.put("STOP")
        print("Producer {} is done".format(self.id))

class Consumer(Process):
    def __init__(self, consumer_id, queue):
        super().__init__()

        self.queue = queue
        self.id = consumer_id

    def run(self):
        for thing in iter(self.queue.get, "STOP"):
            print("Consumer {} doing work".format(self.id))
            time.sleep(random.uniform(1,5))

        print("Consumer {} is done".format(self.id))

def main():
    random.seed(time.time())

    stop_event = Event()
    queue = Queue()

    producers = [Producer(stop_event, i, queue) for i in range(5)]
    consumers = [Consumer(i, queue) for i in range(5)]

    [c.start() for c in consumers]
    [p.start() for p in producers]

    time.sleep(10)

    print("Finishing up")
    stop_event.set()

    [p.join() for p in producers]
    [c.join() for c in consumers]

if __name__ == "__main__":
    main()
