import sys
from exercises.common.node import Node

def traverse_inorder(node):
    if node == None:
        return

    traverse_inorder(node.left)

    print(node)

    traverse_inorder(node.right)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_inorder(tree)
