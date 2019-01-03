import sys
from exercises.binary_trees.node import Node

def tree_width(node):
    width_dict = dict()

    __width(node, 0, width_dict)

    result = 0
    for key, value in width_dict.items():
        result = max(result, value)

    return result

def __width(node, level, width_dict):
    if node == None:
        return

    if level not in width_dict:
        width_dict[level] = 0

    width_dict[level] += 1

    __width(node.left, level + 1, width_dict)
    __width(node.right, level + 1, width_dict)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    width = tree_width(tree)

    print("Tree width is {}".format(width))
