import sys
from exercises.common.binary_search_tree import BinarySearchTree

if __name__ ==  "__main__":
    try:
        values = input("Enter tree nodes in any order: ").strip().split(" ")
        tree = BinarySearchTree.build_from_list(values)
        tree.pretty_print()

        while True:
            value = input("Enter value to insert: ").strip().split(" ")
            tree.insert(value[0])
            tree.pretty_print()
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
