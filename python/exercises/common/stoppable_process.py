from multiprocessing import Process

class StoppableProcess(Process):
    def __init__(self, stop_event):
        super().__init__()

        self.stop_event = stop_event

    def _should_run(self):
        return not self.stop_event.is_set()
