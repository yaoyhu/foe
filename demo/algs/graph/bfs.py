from collections import deque

INFINITY = float("inf")


def bfs(graph: dict, start: str):
    q = deque()
    dist_to = {vertex: INFINITY for vertex in graph.keys()}
    marked = {vertex: False for vertex in graph.keys()}
    edge_to = {vertex: None for vertex in graph.keys()}

    dist_to[start] = 0
    marked[start] = 0
    q.append(start)

    while q:
        v = q.popleft()
        for w in graph[v]:
            if not marked[w]:
                edge_to[w] = v
                dist_to[w] = dist_to[v] + 1  # UDG for +1, DG for +weight
                marked[w] = True
                q.append(w)

    return dist_to, edge_to


graph = {
    "a": ["b"],
    "b": [],
    "c": [],
    "d": ["c"],
    "e": ["i"],
    "f": ["b", "g", "l"],
    "g": ["a", "c", "k"],
    "h": ["c", "d"],
    "i": ["n"],
    "j": ["m", "n", "k"],
    "k": ["l", "h"],
    "l": ["h", "p"],
    "m": ["i"],
    "n": ["o"],
    "o": ["k", "l"],
    "p": [],
}

print(bfs(graph, "j"))
