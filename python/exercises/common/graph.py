from exercises.common.vertex import Vertex

class Graph:
    def __init__(self, bidirectional=True):
        self._vertices = {}
        self._is_bidirectional = bidirectional

    def is_bidirectional(self):
        return self._is_bidirectional

    def add_vertex(self, key):
        vertex = Vertex(key)
        self._vertices[key] = vertex

        return vertex

    def get_vertex(self, key):
        return self._vertices.get(key, None)

    def add_edge(self, from_key, to_key, distance):
        if from_key not in self._vertices:
            self.add_vertex(from_key)

        from_vertex = self._vertices[from_key]

        if to_key not in self._vertices:
            self.add_vertex(to_key)

        to_vertex = self._vertices[to_key]

        from_vertex.add_neighbor(to_vertex, distance)

        if self.is_bidirectional():
            to_vertex.add_neighbor(from_vertex, distance)

    def get_vertices(self):
        return self._vertices.values()

    @staticmethod
    def build_from_list(values):
        return Graph()

    def __str__(self):
        return "\n".join(["{} neighbors: {}".format(v, str([x for x in v.neighbors()])) for v in self])

    def __iter__(self):
        return iter(self._vertices.values())

    def __contains__(self, vertex):
        return vertex in self._vertices
