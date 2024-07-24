class DisjointSets:
    def __init__(self, graph: dict) -> None:
        self.parent = {node: node for node in graph.keys()}
        self.size = {node: 1 for node in graph.keys()}
        self.count = len(graph)

    def find(self, q):
        if q == self.parent[q]:
            return q
        return self.find(self.parent[q])

    def union(self, p, q):
        rootp = self.find(p)
        rootq = self.find(q)
        if rootp == rootq:
            return
        minroot, maxroot = min(rootp, rootq), max(rootq, rootp)
        self.parent[minroot] = maxroot
        self.size[maxroot] += self.size[minroot]
        self.count -= 1


def kruskal(uf: DisjointSets, graph: dict) -> list:
    i = 0
    mst = []
    sorted_arr = sorted(
        [(u, v, w) for u, edges in graph.items() for v, w in edges], key=lambda x: x[2]
    )
    while i < len(sorted_arr) and len(mst) < len(graph.keys()):
        p, q = sorted_arr[i][0], sorted_arr[i][1]
        if uf.find(p) != uf.find(q):
            uf.union(p, q)
            mst.append(sorted_arr[i])
        i += 1
    return mst


graph = {
    "A": [["B", 7], ["D", 5]],
    "B": [["A", 7], ["C", 8], ["D", 9], ["E", 7]],
    "C": [["B", 8], ["E", 5]],
    "D": [["A", 5], ["B", 9], ["E", 15], ["F", 6]],
    "E": [["B", 7], ["C", 5], ["D", 15], ["F", 8], ["G", 9]],
    "F": [["D", 6], ["E", 8], ["G", 11]],
    "G": [["E", 9], ["F", 11]],
}

uf = DisjointSets(graph)
mst = kruskal(uf, graph)
print(mst, "\n", sum(edge[2] for edge in mst))
