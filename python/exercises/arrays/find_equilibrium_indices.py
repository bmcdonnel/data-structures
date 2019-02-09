import sys

def find_equilibrium_indices(array):
    indices = list()
    left_sums = list()

    running_sum = 0
    for x in array:
        running_sum += x
        left_sums.append(running_sum)

    running_sum = 0
    for i, x in enumerate(reversed(array)):
        index = len(array) - 1 - i
        running_sum += x

        if running_sum == left_sums[index]:
            indices.append(index)

    return sorted(indices)

if __name__ ==  "__main__":
    array = [int(x) for x in input("Enter a list of integers: ").strip().split(" ")]

    indices = find_equilibrium_indices(array)

    if len(indices):
        print("Found equilibrium indices at: {}".format(indices))
    else:
        print("No equilibrium indices found")
