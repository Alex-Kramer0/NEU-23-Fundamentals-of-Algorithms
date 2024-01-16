from pprint import pprint
import sys

def bellman_ford(G, s):
    vertices = list(G.keys())
    index_map = {vertex: index for index, vertex in enumerate(vertices)}
    num_vertices = len(vertices)

    d = [float('inf')] * num_vertices
    d[index_map[s]] = 0

    for i in range(num_vertices - 1):
        for u in range(num_vertices):
            for v, w in G[vertices[u]].items():
                if d[index_map[v]] > d[u] + w:
                    d[index_map[v]] = d[u] + w

    # Check for negative cycles
    for u in range(num_vertices):
        for v, w in G[vertices[u]].items():
            if d[index_map[v]] > d[u] + w:
                return False

    return dict(zip(vertices, d))

def main():
    # Define the graph as an adjacency list
    graph = {
        'A': {'B': -1, 'C': 4},
        'B': {'C': 3, 'D': 2, 'E': 2},
        'C': {},
        'D': {'B': 1, 'C': 5},
        'E': {'D': -3}
    }

    # Specify the source vertex
    source_vertex = 'A'

    # Run Bellman-Ford algorithm
    result = bellman_ford(graph, source_vertex)

    # Check for negative cycles
    if result is False:
        print("Graph contains negative cycle!")
    else:
        # Print the shortest distances from the source vertex
        print("Shortest distances from", source_vertex + ":")
        for vertex, distance in result.items():
            print(f"To {vertex}: {distance}")

if __name__ == "__main__":
    main()
