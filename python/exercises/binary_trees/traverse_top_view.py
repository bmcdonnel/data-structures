import sys
from exercises.common.node import Node

# Given a binary tree, print the top view of the nodes. Assume the left and right
#   child of a node line up directly with that node's parent.
#
# Input:  1 2 3 x x 5 6 x x x x 7 8
# Output: 1 2 3 6

def traverse_top_view(tree):
    distances = dict()

    __top_view(tree, 0, 0, distances)

    for key, value in distances.items():
        print(value[0])

def __top_view(node, distance, level, distances):
    if node == None:
        return

    if distance not in distances or level < distances[distance][1]:
        distances[distance] = (node, level)

    __top_view(node.left, distance - 1, level + 1, distances)
    __top_view(node.right, distance + 1, level + 1, distances)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_top_view(tree)
