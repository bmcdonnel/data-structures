import sys
from exercises.common.graph import Graph

if __name__ ==  "__main__":
    try:
        graph = Graph()
        while True:
            vertices = input("Enter vertices to create edges along a path: ").strip().split(" ")
            for i in range(len(vertices) - 1):
                v1 = vertices[i]
                v2 = vertices[i + 1]

                graph.add_edge(v1, v2, 1)

            print(graph)
    except EOFError:
        print()
    except KeyboardInterrupt:
        print()
