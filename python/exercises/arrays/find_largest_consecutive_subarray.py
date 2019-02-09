import sys
import pdb

# Given an array of integers, find largest sub-array formed by consecutive integers. The sub-array should contain all distinct values.
# For example,
# Input: { 2, 0, 2, 1, 4, 3, 1, 0 }
# Output: The largest sub-array is { 0, 2, 1, 4, 3 }

def find_largest_consecutive_subarray(array):
    length = 1
    start_index = 0
    end_index = 0

    for i in range(len(array) - 1):
        min_value = array[i]
        max_value = array[i]

        seen = dict()
        seen[array[i]] = i

        for j in range(i + 1, len(array)):
            value = array[j]

            min_value = min(min_value, value)
            max_value = max(max_value, value)

            max_min_diff = max_value - min_value + 1
            item_count_diff = j - i + 1

            # make sure that this array value hasn't been
            # seen before in the subarray
            if value in seen:
                # break instead of continue cause a duplicate
                # ruins this sub-array chances
                break

            seen[value] = j

            # check that no numbers are skipped by comparing
            # diff of min and max with length of subarray
            if max_min_diff != item_count_diff:
                # continue instead of break cause the next
                # number might complete this sub-array
                continue

            if max_min_diff > length:
                length = max_min_diff
                start_index = i
                end_index = j

    return array[start_index:end_index + 1]


if __name__ ==  "__main__":
    array = [int(x) for x in input("Enter a list of integers: ").strip().split(" ")]

    sub_array = find_largest_consecutive_subarray(array)

    print("The largest sub-array with consecutive, distinct numbers is: {}".format(sub_array))
