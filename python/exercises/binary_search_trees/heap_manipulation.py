import sys
from exercises.common.minheap import MinHeap

if __name__ ==  "__main__":
    try:
        values = input("Enter nodes in any order: ").strip().split(" ")
        heap = MinHeap.build_from_list(values)
        heap.pretty_print()

        while heap.size():
            values = input("Enter values to insert or leave blank to remove one: ").strip().split(" ")

            if values[0] == "":
                value = heap.pop()
                heap.pretty_print()
                print("Removed element {}".format(value))
            else:
                for value in values:
                    heap.insert(int(value))
                heap.pretty_print()
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
