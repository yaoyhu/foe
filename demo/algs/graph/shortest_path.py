class Sg_Shortest_Path:
    def __init__(self) -> None:
        pass

    def dijkstra(self):
        pass

    def bellman_ford(self):
        pass


class All_Shortest_Path:
    def __init__(self, graph: list) -> None:
        self.v = len(graph)
        self.dist = [row[:] for row in graph]

    def floyd_warshall(self):
        for k in range(self.v):
            for i in range(self.v):
                for j in range(self.v):
                    self.dist[i][j] = min(
                        self.dist[i][j], self.dist[i][k] + self.dist[k][j]
                    )
        print(self.dist)


INF = float("inf")

matrix = [[0, INF, -2, INF], [4, 0, 3, INF], [INF, INF, 0, 2], [INF, -1, INF, 0]]
All_Shortest_Path(matrix).floyd_warshall()
