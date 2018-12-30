import sys

# Given an array of integers, find all distinct combinations of given length.
# 
# For example:
#   Input:  {1,2,3}, k=2
#   Output: [{1,2}, {1,3}, {2,3}]
# 
#   Input:  {1,2,1}, k=2
#   Output: [{1,1}, {1,2}]

# TODO: finish this
def find_distinct_combinations(integers):
    return []

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_distinct_combinations <length of combinations> <list of integers>")
        sys.exit(0)

    combo_length = int(sys.argv[1])
    integers = [int(x) for x in sys.argv[2:]]

    combinations = find_distinct_combinations(integers)

    if len(combinations):
        print("found {} distinct combinations of length {}: {}".format(len(combinations), combo_length, combinations))
    else:
        print("no distinct combinations of length {}".format(combo_length))
