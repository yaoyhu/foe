def post_dag(G):
    global time
    time = 0
    for v in G:
        if not marked[v]:
            post_dag_dfs(G, v)


def post_dag_dfs(G, v):
    global time
    time += 1
    timer[v][0] = time
    status[v] = "Activate"
    marked[v] = True
    for w in G[v]:
        if status[w] == "New":
            parent[w] = v
            post_dag_dfs(G, w)
        elif status[w] == "Activate":
            exit
    status[v] = "Finished"
    time += 1
    timer[v][1] = time
    stack.append(v)


keys = [chr(i) for i in range(ord("a"), ord("q"))]
status = {key: "New" for key in keys}
marked = {key: False for key in keys}
timer = {key: [0, 0] for key in keys}
parent = {key: None for key in keys}
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
stack = []

post_dag(graph)
stack.reverse()
print("Topological Sort:", stack)
print("Timing:", timer)
print("Spanning Tree:", parent)
