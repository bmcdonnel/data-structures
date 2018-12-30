import sys

from math import pow

# Given a set S, find the power set of S. A power set of any set S is the set of
#   all possible subsets of S, including empty set and S itself.
# For example:
#   Input:  {x, y, z}
#   Output: {},
#           {x},
#           {y},
#           {x, y},
#           {z},
#           {x, z},
#           {y, z},
#           {x, y, z},

def find_power_set(number_set):
    power_set_size = int(pow(2, len(number_set)))
    list_of_sets = list()

    for i in range(power_set_size):
        thing = list()

        j = 0
        while j < len(number_set):
            if i & (1 << j):
                thing.append(number_set[j])
            j += 1

        list_of_sets.append(thing)

    return list_of_sets

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_power_set <set of integers>")
        sys.exit(0)

    s = [int(x) for x in sys.argv[1:]]

    power_set = find_power_set(s)

    print("power set of {} is: {}".format(s, power_set))
