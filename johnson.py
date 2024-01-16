from dijkstra import dijkstra
from bellman_ford import bellman_ford

def johnson(G):
    # create new vertex and create path from new vertex to all other vertices
    # where each new edge has weight 0
    G[0] = {}  # new 'fake' vertex
    for v in G:
        G[0][v] = 0
    d = bellman_ford(G, 0)
    if d is False:
        return None
    for u in G:
        for v in G[u]:
            G[u][v] = G[u][v] + d[u] - d[v]
    del G[0]
    ans = {}
    for u in G:
        ans[u] = dijkstra(G, u)
    return ans

def main():
    # Define the graph as an adjacency list
    graph = {
        'A': {'B': -1, 'C': 4},
        'B': {'C': 3, 'D': 2, 'E': 2},
        'C': {},
        'D': {'B': 1, 'C': 5},
        'E': {'D': -3}
    }
    # Run Johnson's algorithm
    result = johnson(graph)

    if result is None:
        print("Graph contains negative cycle!")
    else:
        # Print the shortest paths from each vertex
        print("Shortest paths from each vertex:")
        for u, paths in result.items():
            print(f"From {u}:")
            for v, path in paths.items():
                print(f"  To {v}: {'->'.join(map(str, path))}")
if __name__ == "__main__":
    main()