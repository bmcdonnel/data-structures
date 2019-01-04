import sys
from exercises.common.node import Node

def max_sum_path(node):
    sum_dict = dict()

    __sum_paths(node, [], 0, sum_dict)

    result = 0
    node_path = []

    for key, value in sum_dict.items():
        if value[1] > result:
            node_path = value[0]
            result = value[1]

    return node_path, result

def __sum_paths(node, path, current_sum, sum_dict):
    if node == None:
        sum_dict[path[-1]] = (path, current_sum)
        return

    __sum_paths(node.left, path + [node], current_sum + node.value, sum_dict)
    __sum_paths(node.right, path + [node], current_sum + node.value, sum_dict)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    node_path, max_sum = max_sum_path(tree)

    print("Max sum path is {} with path:".format(max_sum))
    print([x.value for x in node_path])
