class Node:
    def __init__(self, x, y, value=None, parent=None):
        # immutable/private members
        self._x = x
        self._y = y
        self._value = value
        self._neighbors = []

        # mutable/public members
        self.parent = parent
        self.f = 0
        self.g = 0
        self.h = 0

    def x(self):
        return self._x

    def y(self):
        return self._y

    def value(self):
        return self._value

    def neighbors(self):
        return iter(self._neighbors)

    def add_neighbor(self, node):
        self._neighbors.append(node)

    def __str__(self):
        return "{}, ({}, {})".format(self._value, self._x, self._y)

    def __repr__(self):
        return "{}, ({}, {})".format(self._value, self._x, self._y)

def maze_input():
    layout = []

    try:
        print("Enter a maze line by line.")
        print("Use the following symbols separated by spaces:")
        print(" '+': starting point")
        print(" '.': open space")
        print(" 'x': obstacle")
        print(" '*': ending point")
        print("Press CTRL+C to finish")

        while True:
            line = input().strip().split(" ")
            layout.append(line)
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()

    return _process_maze_layout(layout)


def _process_maze_layout(layout):
    maze_nodes = []

    prev_line = None
    for y, layout_line in enumerate(layout):
        node_line = []

        prev_node = None
        for x, char in enumerate(layout_line):
            # add new node to the line
            node = Node(x, y, char)
            node_line.append(node)

            if prev_node:
                # add horizontal neighbor references
                node.add_neighbor(prev_node)
                prev_node.add_neighbor(node)

            if prev_line:
                # TODO: add diagonal neighbors
                node.add_neighbor(prev_line[x])
                prev_line[x].add_neighbor(node)

            prev_node = node

            # keep track of start/end positions
            if char == "+":
                start_position = node
            elif char == "*":
                end_position = node

        prev_line = node_line

        maze_nodes.append(node_line)

    return maze_nodes, start_position, end_position

