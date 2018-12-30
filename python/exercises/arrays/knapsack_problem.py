import sys

# In 0-1 Knapsack problem, we are given a set of items, each with a weight and a value
#   and we need to determine the number of each item to include in a collection so that
#   the total weight is less than or equal to a given limit and the total value is as
#   large as possible.
#
#   Please note that the items are indivisible; we can either take an item or not (0-1 property).
#
# For example,
#   Input:
#     values  = [ 20, 5, 10, 40, 15, 25 ]
#     weights = [ 1, 2, 3, 8, 7, 4 ]
#     desired_weight = 10
#   Output: Knapsack value is 60
#     value = 20 + 40 = 60
#     weight = 1 + 8 = 9 < W

# TODO debug this recursion
def knapsack(values, weights, desired_weight):
    if desired_weight < 0:
        return -1

    if len(values) == 0 or desired_weight == 0:
        return 0

    include = values[0] + knapsack(values[1:], weights[1:], desired_weight - weights[0])

    exclude = knapsack(values[1:], weights[1:], desired_weight)

    return max(include, exclude)

if __name__ ==  "__main__":
    if len(sys.argv) < 4:
        print("usage: python -m knapsack_problem <desired weight> <list of values> , <list of weights>")
        sys.exit(0)

    delimiter = -1
    for i, x in enumerate(sys.argv):
        if x == ",":
            delimiter = i

    if delimiter == -1 or delimiter < 2:
        print("please include a ',' delimiter to separate the value and weight arrays")
        sys.exit(0)

    desired_weight = int(sys.argv[1])
    values = [int(x) for x in sys.argv[2:delimiter]]
    weights = [int(x) for x in sys.argv[delimiter + 1:]]

    if len(values) != len(weights):
        print("length of value and weight arrays must be equal")
        sys.exit(0)

    knapsack_value = knapsack(values, weights, desired_weight)

    print("Knapsack value is {}".format(knapsack_value))
