import sys

# Given two sorted arrays a[] and b[] of size m and n each, merge elements of a[]
# with elements of array b[] by maintaining the sorted order. i.e. fill a[] with
# first m smallest elements and fill b[] with remaining elements.
# The conversion should be done in-place and without using any other data structure.
# For example,
# Input:
#   a[] = { 1, 4, 7, 8, 10 }
#   b[] = { 2, 3, 9 }
# Output:
#   a[] = { 1, 2, 3, 4, 7 }
#   b[] = { 8, 9, 10 }

# len(a) should always be >= len(b)
def inplace_merge(a, b):
    for i in range(len(a)):

        # find an element in "a" that is greater than b[0]
        if a[i] <= b[0]:
            continue

        temp = a[i]
        a[i] = b[0]
        b[0] = temp

        # make a note of the element that needs shifting to the right
        first = b[0]

        j = 1
        # shift everything to the left that is smaller than "first"
        while j < len(b) and b[j] < first:
            b[j - 1] = b[j]
            j += 1

        # insert "first" where it belongs
        b[j - 1] = first
        print(i)
        print(a)
        print(b)

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m inplace_merge_two_arrays <list of integers> , <list of integers>")
        sys.exit(0)

    delimiter = -1
    for i, x in enumerate(sys.argv):
        if x == ",":
            delimiter = i

    if delimiter == -1:
        print("please include a ',' delimiter to separate the two arrays")
        sys.exit(0)

    a = [int(x) for x in sys.argv[1:delimiter]]
    b = [int(x) for x in sys.argv[delimiter + 1:]]

    print(a)
    print(b)

    if len(a) >= len(b):
        inplace_merge(a, b)
    else:
        inplace_merge(b, a)

