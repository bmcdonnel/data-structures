from exercises.common.node import Node

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def __str__(self):
        return str(self.root)

    def insert(self, value):
        val = int(value)

        if self.root:
            _insert(self.root, val)
            self.root = _rebalance(self.root)
        else:
            self.root = Node(val)

    def pretty_print(self):
        _print_tree(self.root, 0)
        print()

    @staticmethod
    def build_from_list(values):
        tree = BinarySearchTree()

        for value in values:
            tree.insert(value)

        return tree

def _insert(node, value):
    if value < node.value:
        if node.left:
            _insert(node.left, value)
            node.left = _rebalance(node.left)
        else:
            node.left = Node(value)
    else:
        if node.right:
            _insert(node.right, value)
            node.right = _rebalance(node.right)
        else:
            node.right = Node(value)


def _rebalance(node):
    left_height = node.left.height() if node.left else 0
    right_height = node.right.height() if node.right else 0
    balance = right_height - left_height

    if balance == -2:
        return _rotate_right(node)

    if balance == 2:
        return _rotate_left(node)

    return node

def _rotate_left(pivot):
    temp = pivot.right
    pivot.right = temp.left
    temp.left = pivot

    return temp

def _rotate_right(pivot):
    temp = pivot.left
    pivot.left = temp.right
    temp.right = pivot

    return temp

def _print_tree(node, space_count):
    if node is None:
        return

    space_count += 5

    _print_tree(node.right, space_count)

    print()
    for _ in range(5, space_count):
        print(" ", end="")

    print(node.value, end="")

    _print_tree(node.left, space_count)
