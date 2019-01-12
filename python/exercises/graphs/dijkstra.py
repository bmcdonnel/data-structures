import sys
from exercises.common.graph import Graph

def dijkstra(graph, start, end):
    pass

if __name__ ==  "__main__":
    graph = Graph()
    try:
        while True:
            vertices = input("Enter vertices and weights to create edges (eg - a 1 b 2 c): ").strip().split(" ")
            i = 0
            while i < (len(vertices) - 2):
                v1 = vertices[i]
                weight = int(vertices[i + 1])
                v2 = vertices[i + 2]

                graph.add_edge(v1, v2, weight)

                i += 2

            print(graph)
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()

    start = input("Enter a source node from the graph: ").strip().split()
    end = input("Enter a destination node from the graph: ").strip().split()

    shortest_path = dijkstra(graph, start, end)

    if shortest_path:
        print("Shortest path from {} to {} is: ".format(start, end, shortest_path))
    else:
        print("No path from {} to {}".format(start, end))
