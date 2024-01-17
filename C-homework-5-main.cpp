#include <cstddef>
#include <ios>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "dfs.cpp"
#include "algos.cpp"
#include "graph_reader.cpp"

using namespace std;

//                                    MAIN 
int main(int argc, char* argv[]) {

	int size;
	string graph = "graph-3.txt";
	if (argc > 1) {
		graph = argv[1];
	}
	int** matrix = read_graph(graph,size);	
    cout << "\n";	
    cout << "DFS: \n";
    dfs(0, matrix, size);
    cout << "\n";

    warn_on_negative_edge(matrix, size);

    cout << "\n";
	cout << "Prims: \n";
	mst_prims(matrix, 0, size);

    cout << "\n";
	cout << "Kruskal: \n";
	mst_kruskal(matrix, 0, size);

    cout << "\n";
    cout << "Dijkstra's: \n";
	dijkstra(matrix, 0,size);

    cout << "\n";
    cout << "Bellman Ford's: \n";
    bellman_ford(matrix, size);

	cout << '\n';
}
// END MAIN
