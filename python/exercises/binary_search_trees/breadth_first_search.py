import sys
from queue import Queue
from exercises.common.binary_search_tree import BinarySearchTree

def breadth_first_search_path(tree, value):
    if tree == None:
        return

    q = Queue()
    q.put(tree)

    path = []
    while q.qsize():
        node = q.get()

        path.append(node.value)

        if node.value == value:
            return path, True

        if node.left:
            q.put(node.left)

        if node.right:
            q.put(node.right)

    return path, False

if __name__ ==  "__main__":
    try:
        values = input("Enter tree nodes in any order: ").strip().split(" ")
        tree = BinarySearchTree.build_from_list(values)
        tree.pretty_print()

        while True:
            value = int(input("Enter search value: ").strip().split(" ")[0])
            path, found = breadth_first_search_path(tree.root, value)

            if found:
                print("Found {} along path: {}".format(value, path))
            else:
                print("Did not find {} in tree".format(value))
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
