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

def pop_minimum_f(nodes):
    node = nodes[0]
    index = 0

    for i, x in enumerate(thing[1:]):
        if x.f < node.f:
            node = x
            index = i + 1

    nodes.pop(index)

    return node

if __name__ ==  "__main__":
    maze, start, end = maze_input()

    [print(line) for line in maze]

    path = a_star(maze, start, end)
