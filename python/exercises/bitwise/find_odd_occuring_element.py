import sys

# Given an array of integers, duplicates are present in it in such a way that all duplicates
#   appear even number of times except one which appears odd number of times. Find that odd
#   appearing element in linear time and without using any extra memory.

# For example,
#   Input: arr = [4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3]
#   Output: Odd occurring element is 4

def find_odd_occuring_element(numbers):
    result = 0

    for x in numbers:
        result ^= x

    return result

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_odd_occuring_element <list of integer>")
        sys.exit(0)

    integers = [int(x) for x in sys.argv[1:]]

    odd_element = find_odd_occuring_element(integers)

    print("odd occuring element: {}".format(odd_element))
