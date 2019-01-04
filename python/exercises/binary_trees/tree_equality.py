import sys
from exercises.common.node import Node

def are_trees_equal(node1, node2):
    if node1 == None and node2 == None:
        return True

    return (node1.value == node2.value and
            are_nodes_equal(node1.left, node2.left) and
            are_nodes_equal(node1.right, node2.right))

if __name__ ==  "__main__":
    values = input("Enter first tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree1 = Node.build_from_implicitly_ordered_list(values)

    values = input("Enter second tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree2 = Node.build_from_implicitly_ordered_list(values)

    result = are_trees_equal(tree1, tree2)

    if result:
        print("The trees are equal")
    else:
        print("The trees are NOT equal")
