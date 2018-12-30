class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    @staticmethod
    def build_from_implicitly_ordered_list(values):
        return Node.__build_from_implicit_list(values, 0)

    @staticmethod
    def __build_from_implicit_list(values, i):
        if i >= len(values):
            return None

        node = Node(values[i])
        node.left = Node.__build_from_implicit_list(values, (2 * i) + 1)
        node.right = Node.__build_from_implicit_list(values, (2 * i) + 2)

        return node
