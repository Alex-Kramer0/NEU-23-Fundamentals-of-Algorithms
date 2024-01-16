def dijkstra(G, s):
    def get_path(prev, target):
        path = []
        while target is not None:
            path.append(target)
            target = prev[target]
        return path[::-1]  # Reverse the path because path is created in reverse

    n = len(G)
    dist = [float('inf')] * (n+1)
    prev = [None] * (n+1)
    dist[s] = 0
    Q = set(range(1, n+1))
    paths = set()
    while Q:
        u = min(Q, key=lambda x: dist[x])
        Q.remove(u)
        for v in G[u]:
            alt = dist[u] + G[u][v]
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
            p = tuple(get_path(prev, v)) # lists cannot be hashed, so convert to tuple
            paths.add(p)
    return paths

def main_dijkstra():
    # Define the graph as an adjacency list
    graph = {
        1: {2: 1, 3: 4},
        2: {3: 2, 4: 5},
        3: {4: 1},
        4: {}
    }

    # Specify the source vertex
    source_vertex = 1

    # Run Dijkstra's algorithm
    paths = dijkstra(graph, source_vertex)

    # Print the shortest paths from the source vertex
    print("Shortest paths from", source_vertex, ":")
    for path in paths:
        print("->".join(map(str, path)))

if __name__ == "__main__":
    main_dijkstra()

