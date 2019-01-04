import sys
from collections import deque
from exercises.common.node import Node

def traverse_spiral_order(tree):
    if tree == None:
        return

    d = deque()
    d.append(tree)

    flag = False

    while len(d):
        count = len(d)

        if flag:
            flag = False

            # pop left, append right
            while count:
                node = d.popleft()

                print(node)

                if node.left:
                    d.append(node.left)

                if node.right:
                    d.append(node.right)

                count -= 1
        else:
            flag = True

            # pop right, append left
            while count:
                node = d.pop()

                print(node)

                if node.right:
                    d.appendleft(node.right)

                if node.left:
                    d.appendleft(node.left)

                count -= 1

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    traverse_spiral_order(tree)
