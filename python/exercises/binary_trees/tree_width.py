import sys
from exercises.common.node import Node

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    print("Tree width is {}".format(Node.max_width(tree)))
