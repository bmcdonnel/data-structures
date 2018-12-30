import sys
from exercises.binary_trees.node import Node

def are_trees_equal(tree1, tree2):
    if tree1 == None and tree2 == None:
        return True

    return (tree1.value == tree2.value and
            are_trees_equal(tree1.left, tree2.left) and
            are_trees_equal(tree1.right, tree2.right))

if __name__ ==  "__main__":
    values = [int(x) for x in input("Enter first tree (implicit ordering): ").split(" ")]
    tree1 = Node.build_from_implicitly_ordered_list(values)

    values = [int(x) for x in input("Enter second tree (implicit ordering): ").split(" ")]
    tree2 = Node.build_from_implicitly_ordered_list(values)

    result = are_trees_equal(tree1, tree2)

    if result:
        print("The trees are equal")
    else:
        print("The trees are NOT equal")
