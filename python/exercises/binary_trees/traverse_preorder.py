import sys
from exercises.common.node import Node

def traverse_preorder(node):
    if node == None:
        return

    print(node)
    traverse_preorder(node.left)
    traverse_preorder(node.right)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_preorder(tree)
