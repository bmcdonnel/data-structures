import random
import time

from exercises.common.stoppable_process import StoppableProcess
from multiprocessing import Process, Event, Value, Lock, Semaphore

class Reader(StoppableProcess):
    def __init__(
            self,
            stop_event,
            id,
            mutex,
            reader_count,
            room_empty,
            turnstile):
        super().__init__(stop_event)

        self.id = id
        self.mutex = mutex
        self.reader_count = reader_count
        self.room_empty = room_empty
        self.turnstile = turnstile

    def run(self):
        while self._should_run():
            # wait to go through the turnstile
            self.turnstile.acquire()
            self.turnstile.release()

            print("Reader {} entering the room".format(self.id))

            self.turn_on_light()

            time.sleep(random.uniform(0,5))

            print("Reader {} leaving the room".format(self.id))

            self.turn_off_light()

        print("Reader {} is done".format(self.id))

    def turn_on_light(self):
        self.mutex.acquire()

        self.reader_count.value += 1
        if self.reader_count.value == 1:
            # first reader turns on the light
            self.room_empty.acquire()
            print("Reader {} turned on the light".format(self.id))

        self.mutex.release()

    def turn_off_light(self):
        self.mutex.acquire()

        self.reader_count.value -= 1
        if self.reader_count.value == 0:
            # last reader to leave turns out the light
            self.room_empty.release()
            print("Reader {} turned off the light".format(self.id))

        self.mutex.release()

class Writer(StoppableProcess):
    def __init__(self, stop_event, id, room_empty, turnstile):
        super().__init__(stop_event)

        self.id = id
        self.room_empty = room_empty
        self.turnstile = turnstile

    def run(self):
        while self._should_run():
            # block any addtional readers/writers from entering the turnstile
            self.turnstile.acquire()

            print("Writer {} entered the room".format(self.id))

            # wait for all current readers to leave the room
            self.room_empty.acquire()

            print("Writer {} is alone in the room".format(self.id))
            time.sleep(random.uniform(0,5))

            # signal to waiting readers/writers that they may enter
            self.turnstile.release()

            # leave the room
            self.room_empty.release()

            print("Writer {} left the room".format(self.id))

        print("Writer {} is done".format(self.id))

def main():
    random.seed(time.time())

    stop_event = Event()

    lock = Lock()
    reader_count = Value('i', 0)
    room_empty = Semaphore(1)
    turnstile = Semaphore(1)

    readers = [Reader(stop_event, i, lock, reader_count, room_empty, turnstile) for i in range(5)]
    writers = [Writer(stop_event, i, room_empty, turnstile) for i in range(3)]

    [r.start() for r in readers]
    [w.start() for w in writers]

    time.sleep(10)

    print("Finishing up")
    stop_event.set()

    [w.join() for w in writers]
    [r.join() for r in readers]

if __name__ == "__main__":
    main()
