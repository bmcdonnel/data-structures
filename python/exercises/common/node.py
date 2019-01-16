class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.parent = None

    @staticmethod
    def build_from_implicitly_ordered_list(values):
        return _build_from_implicit_list(values, 0)

    def height(self):
        return _node_height(self)

    def max_width(self):
        width_dict = dict()

        _node_width(self, 0, width_dict)

        result = 0
        for _, value in width_dict.items():
            result = max(result, value)

        return result

    def __eq__(self, other):
        return _are_nodes_equal(self, other)

    def __lt__(self, other):
        return self.value < other.value

    def __str__(self):
        return str(self.value)

def _are_nodes_equal(node1, node2):
    # if the nodes are both None, they're equal
    if node1 is None and node2 is None:
        return True

    # if either node is None, they're not equal
    if node1 is None or node2 is None:
        return False

    # neither node is None, so test the values and their children
    return (node1.value == node2.value and
            _are_nodes_equal(node1.left, node2.left) and
            _are_nodes_equal(node1.right, node2.right))

def _node_height(node):
    if node is None:
        return 0

    left_height = _node_height(node.left)
    right_height = _node_height(node.right)

    return max(left_height, right_height) + 1

def _node_width(node, level, width_dict):
    if node is None:
        return

    if level not in width_dict:
        width_dict[level] = 0

    width_dict[level] += 1

    _node_width(node.left, level + 1, width_dict)
    _node_width(node.right, level + 1, width_dict)

def _build_from_implicit_list(values, i):
    if i >= len(values) or values[i].lower() == "x":
        return None

    node = Node(int(values[i]))
    node.left = _build_from_implicit_list(values, (2 * i) + 1)
    node.right = _build_from_implicit_list(values, (2 * i) + 2)

    return node
