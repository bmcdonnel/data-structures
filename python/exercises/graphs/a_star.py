import sys

class Node:
    def __init__(self, position=None, value=None, parent=None):
        self.position = position
        self.value = value
        self.parent = parent
        self.neighbors = []

        self.f = 0
        self.g = 0
        self.h = 0

    def __eq__(self, other):
        return self.position == other.position

    def __str__(self):
        return "({}, {})".format(self.value, len(self.neighbors))

    def __repr__(self):
        return "({}, {})".format(self.value, len(self.neighbors))

def process_maze_layout(layout):
    maze_nodes = []

    prev_line = None
    for y, layout_line in enumerate(layout):
        node_line = []

        prev_node = None
        for x, char in enumerate(layout_line):
            # add new node to the line
            node = Node((x, y), char)
            node_line.append(node)

            if prev_node:
                # add horizontal neighbor references
                node.neighbors.append(prev_node)
                prev_node.neighbors.append(node)

            if prev_line:
                # TODO: add in diagonal neighbors
                node.neighbors.append(prev_line[x])
                prev_line[x].neighbors.append(node)

            prev_node = node

            # keep track of start/end positions
            if char == "+":
                start_position = node
            elif char == "*":
                end_position = node

        prev_line = node_line

        maze_nodes.append(node_line)

    return maze_nodes, start_position, end_position

if __name__ ==  "__main__":
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

    maze, start, end = process_maze_layout(layout)

    [print(line) for line in maze]
