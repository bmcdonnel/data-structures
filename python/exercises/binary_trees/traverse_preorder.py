import sys
from exercises.binary_trees.node import Node

def traverse_preorder(tree):
    if tree == None:
        return

    print(tree)
    traverse_preorder(tree.left)
    traverse_preorder(tree.right)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_preorder(tree)
