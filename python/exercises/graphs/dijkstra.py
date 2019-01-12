import sys
from exercises.common.graph import Graph

def dijkstra(graph, start, end):
    unvisited_vertices = list(graph)
    previous_vertices = dict()
    distances_to_start = dict()

    distances_to_start[start] = 0

    while len(unvisited_vertices):
        current = vertex_with_min_distance(unvisited_vertices, distances_to_start)

        unvisited_vertices.remove(current)

        if current == end:
            break

        for neighbor, distance in current.neighbors():
            alt = distance + distances_to_start[current]

            if neighbor not in distances_to_start or alt < distances_to_start[neighbor]:
                distances_to_start[neighbor] = alt
                previous_vertices[neighbor] = current

    return collect_path(previous_vertices, start, end)

def collect_path(previous_vertices, start, end):
    path = list()
    v = end

    while v != start:
        path.append(v)
        v = previous_vertices[v]

    path.append(start)

    return list(reversed(path))

# TODO: convert this to a priority queue/min-heap
def vertex_with_min_distance(vertices, distances):
    vertex = vertices[0]
    for v in vertices[1:]:
        if v in distances and distances[v] < distances[vertex]:
            vertex = v

    return vertex

if __name__ ==  "__main__":
    graph = Graph()
    try:
        while True:
            vertices = input("Enter vertices and distances to create edges (eg - a 1 b 2 c): ").strip().split(" ")
            i = 0
            while i < (len(vertices) - 2):
                v1 = vertices[i]
                distance = int(vertices[i + 1])
                v2 = vertices[i + 2]

                graph.add_edge(v1, v2, distance)

                i += 2

            print(graph)
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()

    try:
        start_key = input("Enter a source node from the graph: ").strip().split()[0]
        end_key = input("Enter a destination node from the graph: ").strip().split()[0]

        start = graph.get_vertex(start_key)
        end = graph.get_vertex(end_key)

        shortest_path = dijkstra(graph, start, end)

        if shortest_path:
            print("Shortest path from {} to {} is: {}".format(start, end, shortest_path))
        else:
            print("No path from {} to {}".format(start, end))
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
