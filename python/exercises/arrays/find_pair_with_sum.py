import sys

def find_pair_with_sum(target_sum, integers):
    compliments = dict()

    for i, value in enumerate(integers):
        difference = target_sum - value
        if difference in compliments:
            return True, (compliments[difference], i)
        else:
            compliments[value] = i

    return False, (None, None)

if __name__ ==  "__main__":
    integers = [int(x) for x in input("Enter a list of integers: ").strip().split(" ")]

    target_sum = int(input("Enter the target sum: ").strip())

    sum_exists, indices = find_pair_with_sum(target_sum, integers)

    if sum_exists:
        print("sum {} was found at indices {} and {}".format(target_sum, indices[0], indices[1]))
    else:
        print("sum {} was not found".format(target_sum))
