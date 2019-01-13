import sys
from exercises.common.maze import maze_input

def a_star(maze, start, end):
    open_nodes = []
    closed_nodes = []

    open_nodes.append(start)

    while len(open_nodes):
        current_node = pop_minimum_f(open_nodes)
        closed_nodes.append(current_node)

        if current_node == end:
            break

        for neighbor in current_node.neighbors():
            if (neighbor in closed_nodes or
                neighbor in open_nodes or
                neighbor.blocked):
                continue

            x_diff = end.x() - neighbor.x()
            y_diff = end.y() - neighbor.y()

            # TODO maybe precompute these?
            neighbor.g = current_node.g + 1
            neighbor.h = (x_diff * x_diff) + (y_diff * y_diff)
            neighbor.f = neighbor.g + neighbor.h
            neighbor.parent = current_node

            open_nodes.append(neighbor)

    if current_node != end:
        return None

    path = []
    while current_node != start:
        path.append(current_node)
        current_node = current_node.parent

    path.append(start)

    return list(reversed(path))

def pop_minimum_f(nodes):
    node = nodes[0]
    index = 0

    for i, x in enumerate(nodes[1:]):
        if x.f < node.f:
            node = x
            index = i + 1

    nodes.pop(index)

    return node

if __name__ ==  "__main__":
    maze, start, end = maze_input()

    path = a_star(maze, start, end)

    # mark the chosen path
    for node in path[1:-1]:
        node.value = "o"

    for line in maze:
        print(" ".join([x.value for x in line]))
