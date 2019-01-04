import sys
from exercises.common.node import Node

def traverse_left_view(tree):
    level_dict = dict()

    __left_view(tree, 0, level_dict)

def __left_view(node, level, level_dict):
    if node == None:
        return

    if level not in level_dict:
        level_dict[level] = node
        print(node)

    __left_view(node.left, level + 1, level_dict)
    __left_view(node.right, level + 1, level_dict)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_left_view(tree)
