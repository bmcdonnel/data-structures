import sys
from exercises.binary_trees.node import Node

def tree_height(tree):
    if tree == None:
        return 0

    left_height = tree_height(tree.left)
    right_height = tree_height(tree.right)

    return max(left_height, right_height) + 1

if __name__ ==  "__main__":
    values = [int(x) for x in input("Enter tree (implicit ordering): ").split(" ")]
    tree = Node.build_from_implicitly_ordered_list(values)

    result = tree_height(tree)

    print("Height: {}".format(result))
