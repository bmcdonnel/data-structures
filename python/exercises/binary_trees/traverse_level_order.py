import sys
from queue import Queue
from exercises.common.node import Node

def traverse_level_order(tree):
    if tree == None:
        return

    q = Queue()

    q.put(tree)

    while q.qsize():
        node = q.get()

        print(node)

        if node.left:
            q.put(node.left)

        if node.right:
            q.put(node.right)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_level_order(tree)
