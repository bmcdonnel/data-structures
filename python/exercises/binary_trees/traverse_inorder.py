import sys
from exercises.binary_trees.node import Node

def traverse_inorder(tree):
    if tree == None:
        return

    traverse_inorder(tree.left)

    print(tree)

    traverse_inorder(tree.right)

if __name__ ==  "__main__":
    values = [int(x) for x in input("Enter tree (implicit ordering): ").split(" ")]
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_inorder(tree)
