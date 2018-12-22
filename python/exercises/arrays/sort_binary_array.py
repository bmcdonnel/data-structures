import sys
from functools import reduce

def sort_binary_array(array):
    num_ones = reduce(lambda x, y: x + y, array)
    num_zeroes = len(array) - num_ones

    for i in range(num_zeroes):
        array[i] = 0

    for i in range(num_ones):
        array[num_zeroes + i] = 1

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m sort_binary_array <list of 1's and 0's>")
        sys.exit(0)

    array = [int(x) for x in sys.argv[1:]]

    sort_binary_array(array)

    print(array)
