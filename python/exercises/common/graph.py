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

    def add_edge(self, from_key, to_key, weight):
        if from_key not in self._vertices:
            self.add_vertex(from_key)

        from_vertex = self._vertices[from_key]

        if to_key not in self._vertices:
            self.add_vertex(to_key)

        to_vertex = self._vertices[to_key]

        from_vertex.add_neighbor(to_vertex, weight)

        if self.is_bidirectional():
            to_vertex.add_neighbor(from_vertex, weight)

    @staticmethod
    def build_from_list(values):
        return Graph()

    def __str__(self):
        return "\n".join([str(v) for v in self._vertices.values()])
