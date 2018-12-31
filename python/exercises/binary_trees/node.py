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
        if i >= len(values) or values[i].lower() == "x":
            return None

        node = Node(values[i])
        node.left = Node.__build_from_implicit_list(values, (2 * i) + 1)
        node.right = Node.__build_from_implicit_list(values, (2 * i) + 2)

        return node

    def __str__(self):
        return str(self.value)
