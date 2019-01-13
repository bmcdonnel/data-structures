import sys

def mergesort(array):
    aux = [0] * len(array)

    _mergesort(array, aux, 0, len(array) - 1)

def _mergesort(array, aux, begin, end):
    if end <= begin:
        return

    middle = (begin + end) // 2

    _mergesort(array, aux, begin, middle)   # front half
    _mergesort(array, aux, middle + 1, end) # back half

    _merge(array, aux, begin, middle + 1, end) # merge them together

def _merge(array, aux, begin, middle, end):
    left = begin
    right = middle
    temp = begin

    # merge left and right arrays until either runs out
    while left <= middle - 1 and right <= end:
        if array[left] <= array[right]:
            aux[temp] = array[left]
            left += 1
        else:
            aux[temp] = array[right]
            right += 1

        temp += 1

    # finish off the remainder of the left array
    while left <= middle - 1:
        aux[temp] = array[left]
        temp += 1
        left += 1

    # finish off the remainder of the right array
    while right <= end:
        aux[temp] = array[right]
        temp += 1
        right += 1

    # copy them back from the aux array
    for i in range(begin, end + 1):
        array[i] = aux[i]

if __name__ ==  "__main__":
    try:
        values = input("Enter unsorted integers: ").strip().split(" ")
        values = [int(v) for v in values]

        mergesort(values)

        print(" ".join([str(v) for v in values]))
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
