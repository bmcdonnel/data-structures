import sys

# Given an array of integers, find all distinct combinations of given length.
# 
# For example:
#   Input:  {1,2,3}, k=2
#   Output: [{1,2}, {1,3}, {2,3}]
# 
#   Input:  {1,2,1}, k=2
#   Output: [{1,1}, {1,2}]

def find_distinct_combinations(integers, k):
    combinations = []

    _find_distinct_combinations(integers, combinations, [], 0, k)

    return combinations

def _find_distinct_combinations(integers, results, combination, i, k):
    if k == 0:
        results.append(combination)
        return

    if i == len(integers):
        return

    _find_distinct_combinations(
        integers,
        results,
        combination + [integers[i]],
        i + 1,
        k - 1
    )

    _find_distinct_combinations(
        integers,
        results,
        combination,
        i + 1,
        k
    )

if __name__ ==  "__main__":
    integers = [int(x) for x in input("Enter list of integers: ").strip().split(" ")]
    combo_length = int(input("Enter combination length: ").strip())

    combinations = find_distinct_combinations(integers, combo_length)

    if len(combinations):
        print("found {} distinct combinations of length {}: {}".format(len(combinations), combo_length, combinations))
    else:
        print("no distinct combinations of length {}".format(combo_length))
