import sys
from exercises.common.graph import Graph

if __name__ ==  "__main__":
    try:
        graph = Graph()
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
