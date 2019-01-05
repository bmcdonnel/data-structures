from exercises.common.node import Node

class BinarySearchTree(object):
    def __init__(self):
        self.root = None

    def __str__(self):
        _print_tree(self.root, 0)
        return ""

    def insert(self, value):
        v = int(value)

        if self.root:
            _insert(self.root, v)
        else:
            self.root = Node(v)

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
        else:
            node.left = Node(value)
    else:
        if node.right:
            _insert(node.right, value)
        else:
            node.right = Node(value)

def _print_tree(node, space_count):
    if node is None:
        return

    space_count += 5

    _print_tree(node.right, space_count)

    print("")
    for i in range(5, space_count):
        print(" ", end="")

    print(node.value, end="")

    _print_tree(node.left, space_count)
