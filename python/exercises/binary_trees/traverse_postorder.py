import sys
from exercises.binary_trees.node import Node

def traverse_postorder(tree):
    if tree == None:
        return

    traverse_postorder(tree.left)
    traverse_postorder(tree.right)
    print(tree)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_postorder(tree)
