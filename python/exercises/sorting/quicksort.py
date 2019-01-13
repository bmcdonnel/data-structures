import sys

def quicksort(array):
    return _quicksort(array, 0, len(array) - 1)

def _quicksort(array, low, high):
    if low >= high:
        return

    p = partition(array, low, high)

    _quicksort(array, low, p)
    _quicksort(array, p + 1, high)

def partition(array, low, high):
    pivot = array[low]
    i = low
    j = high

    while True:
        # find the first item greater than the pivot from the left
        while(array[i] < pivot):
            i += 1

        # find the first item less than the pivot from the right
        while(array[j] > pivot):
            j -= 1

        if i >= j:
            # indices are crossed, so we're done
            return j

        # swap the two items
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

        i += 1
        j -= 1

if __name__ ==  "__main__":
    try:
        values = input("Enter unsorted integers: ").strip().split(" ")
        values = [int(v) for v in values]

        quicksort(values)

        print(" ".join([str(v) for v in values]))
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
