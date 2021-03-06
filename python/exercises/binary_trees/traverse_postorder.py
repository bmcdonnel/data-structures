import sys
from exercises.common.node import Node

def traverse_postorder(node):
    if node == None:
        return

    traverse_postorder(node.left)
    traverse_postorder(node.right)
    print(node)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_postorder(tree)
