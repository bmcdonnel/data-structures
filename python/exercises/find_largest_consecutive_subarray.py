import sys

# Given an array of integers, find largest sub-array formed by consecutive integers. The sub-array should contain all distinct values.
# For example,
# Input: { 2, 0, 2, 1, 4, 3, 1, 0 }
# Output: The largest sub-array is { 0, 2, 1, 4, 3 }

def ensure_consecutive_and_unique(array):
    min_value = array[0]
    max_value = array[0]
    seen = dict()

    # check for uniqueness of each element
    for i, x in enumerate(array):
        if x in seen:
            return False
        else:
            seen[x] = i

        # also find the min and max as we loop through the array
        min_value = min(min_value, array[i])
        max_value = max(max_value, array[i])

    # check that no numbers are skipped by comparing diff of min and max with length
    if max_value - min_value + 1 != len(array):
        return False

    return True

def find_largest_consecutive_subarray(array):
    length = 1
    start_index = 0
    end_index = 0

    for i, x in enumerate(array):
        # TODO: finish this
        pass
        

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_largest_consecutive_subarray <list of integers>")
        sys.exit(0)

    array = [int(x) for x in sys.argv[1:]]

    find_largest_consecutive_subarray(array)
