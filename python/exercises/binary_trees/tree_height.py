import sys
from exercises.common.node import Node

def tree_height(node):
    if node == None:
        return 0

    left_height = tree_height(node.left)
    right_height = tree_height(node.right)

    return max(left_height, right_height) + 1

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    result = tree_height(tree)

    print("Height: {}".format(result))
