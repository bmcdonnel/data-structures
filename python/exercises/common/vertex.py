class Vertex:
    def __init__(self, key):
        self._key = key
        self._neighbors = {}

    def add_neighbor(self, vertex, distance=0):
        self._neighbors[vertex] = distance

    def get_key(self):
        return self._key

    def get_distance(self, neighbor):
        return self._neighbors[neighbor]

    def neighbors(self):
        return iter(self._neighbors.items())

    def __repr__(self):
        return self._key

    def __str__(self):
        return self._key

    def __iter__(self):
        return iter(self._vertices.values())

