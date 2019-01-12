class Vertex:
    def __init__(self, key):
        self._key = key
        self._neighbors = {}
        self._weights = {}

    def add_neighbor(self, vertex, weight=0):
        key = vertex.get_key()

        self._neighbors[key] = vertex
        self._weights[key] = weight

    def get_key(self):
        return self._key

    def get_neighbors(self):
        return self._neighbors.keys()

    def get_weight(self, neighbor_key):
        return self._neighbors[neighbor_key]

    def __str__(self):
        return "{} neighbors: {}".format(self.get_key(), [x for x in self._neighbors.keys()])
