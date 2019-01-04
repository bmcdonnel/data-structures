import sys
from exercises.common.node import Node

if __name__ ==  "__main__":
    values = input("Enter first tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree1 = Node.build_from_implicitly_ordered_list(values)

    values = input("Enter second tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree2 = Node.build_from_implicitly_ordered_list(values)

    if tree1 == tree2:
        print("The trees are equal")
    else:
        print("The trees are NOT equal")
