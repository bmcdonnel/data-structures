import sys
from collections import deque
from exercises.common.node import Node

def traverse_spiral_order(tree):
    if tree == None: return

    d = deque()
    d.append(tree)

    pop_from_right = True

    while len(d):
        count = len(d)
        values = list()

        if pop_from_right:
            # pop right, append left
            while count:
                node = d.pop()

                values.append(str(node.value))

                if node.right: d.appendleft(node.right)
                if node.left: d.appendleft(node.left)

                count -= 1
        else:
            # pop left, append right
            while count:
                node = d.popleft()

                values.append(str(node.value))

                if node.left: d.append(node.left)
                if node.right: d.append(node.right)

                count -= 1

        print(",".join(values))
        pop_from_right = not pop_from_right

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_spiral_order(tree)
