import sys

# Given an array of integers containing duplicates, return the majority element in an
#   array if present. A majority element appears more than n/2 times where n is the
#   size of the array.
#
# For example, the majority element is 2 in the array {2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2}

def find_majority_element(integers):
    counts = dict()

    for x in integers:
        if x in counts:
            counts[x] += 1
        else:
            counts[x] = 1

        if counts[x] > len(integers)/2:
            return True, x, counts[x]

    return False, None, 0

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_majority_element <list of integers>")
        sys.exit(0)

    integers = [int(x) for x in sys.argv[1:]]

    exists, majority_element, count = find_majority_element(integers)

    if exists:
        print("majority element is {}, appearing {} times in {} elements".format(majority_element, count, len(integers)))
    else:
        print("no majority element found")
