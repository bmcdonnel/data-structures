class MinHeap:
    def __init__(self, size=256):
        self._heap = [None] * size
        self._insert_index = 0

    def size(self):
        return self._insert_index

    def insert(self, value):
        val = int(value)

        if self._insert_index >= len(self._heap):
            size = len(self._heap)

            self._heap = self._heap + [None] * size

        self._heap[self._insert_index] = val

        _repair_upward(self._heap, self._insert_index)

        self._insert_index += 1

    def pop(self):
        value = self._heap[0]

        self._insert_index -= 1

        self._heap[0] = self._heap[self._insert_index]
        self._heap[self._insert_index] = None

        _repair_downward(self._heap, 0)

        return value

    def pretty_print(self):
        _print_heap(self._heap, 0, 0)
        print()

    @staticmethod
    def build_from_list(values):
        heap = MinHeap()

        for value in values:
            heap.insert(value)

        return heap

def _repair_upward(array, index):
    if index == 0:
        return

    parent_index = _parent_index(index)
    parent = array[parent_index]

    if array[index] < parent:
        array[parent_index] = array[index]
        array[index] = parent

    _repair_upward(array, parent_index)

def _repair_downward(array, index):
    right_index = _right_child_index(index)
    left_index = _left_child_index(index)

    if (right_index >= len(array) or left_index >= len(array) or
        (array[right_index] is None and array[left_index] is None)):
        return

    right_child = array[right_index]
    left_child = array[left_index]

    # choose the smaller of the two children for a potential swap
    if right_child is None:
        i = left_index
        val = left_child
    elif left_child is None:
        i = right_index
        val = right_child
    elif right_child < left_child:
        i = right_index
        val = right_child
    else:
        i = left_index
        val = left_child

    # if the child is smaller, do the swap
    if array[i] < array[index]:
        array[i] = array[index]
        array[index] = val

    _repair_downward(array, i)

def _parent_index(index):
    return (index - 1) // 2

def _left_child_index(index):
    return (2 * index) + 1

def _right_child_index(index):
    return (2 * index) + 2

def _print_heap(array, index, space_count):
    if index >= len(array) or array[index] is None:
        return

    space_count += 5

    _print_heap(array, _right_child_index(index), space_count)

    print()
    for _ in range(5, space_count):
        print(" ", end="")

    print(array[index], end="")

    _print_heap(array, _left_child_index(index), space_count)
