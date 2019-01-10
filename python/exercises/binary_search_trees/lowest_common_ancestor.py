import sys
from exercises.common.binary_search_tree import BinarySearchTree

def lowest_common_ancestor(tree, value1, value2):
    # TODO should also return None if either value1 or value2 is not present in the tree
    if tree is None:
        return None

    if value1 < tree.value and value2 < tree.value:
        return lowest_common_ancestor(tree.left, value1, value2)
    elif value1 > tree.value and value2 > tree.value:
        return lowest_common_ancestor(tree.right, value1, value2)

    return tree

if __name__ ==  "__main__":
    try:
        values = input("Enter tree nodes in any order: ").strip().split(" ")
        tree = BinarySearchTree.build_from_list(values)
        tree.pretty_print()

        value1 = int(input("Enter first node: ").strip().split(" ")[0])
        value2 = int(input("Enter second node: ").strip().split(" ")[0])

        lca = lowest_common_ancestor(tree.root, value1, value2)

        if lca:
            print("Lowest common ancestor of {} and {} is {}".format(value1, value2, lca.value))
        else:
            print("No lowest common ancestor found")
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
