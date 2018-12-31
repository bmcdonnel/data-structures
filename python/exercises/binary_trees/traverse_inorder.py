import sys
from exercises.binary_trees.node import Node

def traverse_inorder(tree):
    if tree == None:
        return

    traverse_inorder(tree.left)

    print(tree)

    traverse_inorder(tree.right)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_inorder(tree)
