import sys
from exercises.common.binary_search_tree import BinarySearchTree

def depth_first_search_path(tree, value):
    if tree == None:
        return

    stack = list()
    stack.append(tree)

    path = []
    while len(stack):
        node = stack.pop(-1)

        path.append(node.value)

        if node.value == value:
            return path, True

        if node.left:
            stack.append(node.left)

        if node.right:
            stack.append(node.right)

    return path, False

if __name__ ==  "__main__":
    try:
        values = input("Enter tree nodes in any order: ").strip().split(" ")
        tree = BinarySearchTree.build_from_list(values)
        tree.pretty_print()

        while True:
            value = int(input("Enter search value: ").strip().split(" ")[0])
            path, found = depth_first_search_path(tree.root, value)

            if found:
                print("Found {} along path: {}".format(value, path))
            else:
                print("Did not find {} in tree".format(value))
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
