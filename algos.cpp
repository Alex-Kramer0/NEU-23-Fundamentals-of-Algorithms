#include <iostream>
#include "pqueue.cpp"
#include "DistTo.cpp"
#include "merge_sort.cpp"
#include "WQUF.cpp"

using namespace std;
void dijkstra(int** G, int start, int const SIZE) {
	int* distance_to = new int[SIZE];
	bool* seen = new bool[SIZE];
	pqueue<DistTo> pq;
	int* parent = new int[SIZE];
	for (size_t i = 0; i < SIZE; ++i) {
		seen[i] = false;
		distance_to[i] = INT_MAX;
		parent[i] = -1;
	}
	distance_to[start] = 0;
	pq.enqueue(DistTo(start,0));
	while (!pq.is_empty()) {
		DistTo dist_to = pq.deque();
		int accumulative_dist = dist_to.accumulative_distance;
		int vertex = dist_to.vertex;
		while (seen[vertex]) {
			if (pq.is_empty()) {
				cerr << "empty_queue, something went wrong\n";
				return;
			}
			DistTo dist_to = pq.deque();
			int accumulative_dist = dist_to.accumulative_distance;
			int vertex = dist_to.vertex;
		}
		for (int i = 0; i < SIZE; ++i) {
			if (G[vertex][i] != 0 && 
					(accumulative_dist + G[vertex][i]) < distance_to[i]) {
				distance_to[i] = (accumulative_dist + G[vertex][i]);
				pq.enqueue(DistTo(i,distance_to[i]));
				parent[i] = vertex;
			}
		}
	}
	for (int end = 1; end < SIZE; ++end) {
		cout << "dist from " << start << " to " << end << " is " <<  distance_to[end] << "\t: ";
		int i = end;
		// print reversed path by chasing parents
		cout << "END ";
		while(parent[i] != -1) {
			cout << i << "<-";
			i = parent[i];	
		}
		cout << 0 << "<- START\n";

	}
}
void warn_on_negative_edge(int** G, int const SIZE) {
	for (size_t r = 0; r < SIZE; r++) {
		for (size_t c = 0; c < SIZE; c++) {
			if (G[r][c] < 0) {
				cerr << "negative edge detected, result may not be correct\n";
				return;
			}
		}
	}
}
void relax(int a, int b, long long* distance_to, Edge const& edge,int* parents) {
	if (distance_to[a] != INT_MAX && distance_to[b] > distance_to[a] + edge.dist) {
		distance_to[b] = distance_to[a] + edge.dist;
		parents[b] = a;
	}
}
void bellman_ford(int** G, int const SIZE) {
	// find all edges, put in edges array
	int edges_size = 0;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			if (G[r][c] != 0) {
				edges_size++;
			}
		}
	}
	edges_size /=2;
		// init array
	Edge edges[edges_size];
	int count=0;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			if (G[r][c] != 0) {
				edges[count++] = Edge(c,r,G[r][c]);
			}
			if (c == r) {
				break;
			}
		}
	}
	// setup other arrays
	int start = 0;
	long long* distance_to = new long long[SIZE];
	int* parents = new int[SIZE];
		
	for (size_t i = 0; i < SIZE; i++) {
		parents[i] = -1;
		distance_to[i] = INT_MAX;
	}
	distance_to[start] = 0;
	// relax loop
	for (size_t i = 0; i < SIZE; i++) {
		for (size_t j = 0; j < edges_size; j++) {
			int a = edges[j].point_a;
			int b = edges[j].point_b;
			int dist = edges[j].dist;
			relax(a,b,distance_to, edges[j], parents);
			relax(b,a,distance_to, edges[j], parents); // relax bopth sides
		}
	}
	// check -cycle
	
	for (int i = 0; i < edges_size; i++) {
		Edge edge = edges[i];
		int a = edge.point_a;
		int b = edge.point_b;
		int dist = edge.dist;
		if (distance_to[b] > distance_to[a] + dist) {
			cout << "negative cycle\n";
			return;
		}
	}
	for (int end = 1; end < SIZE; ++end) {
		cout << "dist from " << start << " to " << end << " is " <<  distance_to[end] << "\t: ";
		int i = end;
		// print reversed path by chasing parents
		cout << "END ";
		while(parents[i] != -1) {
			cout << i << "<-";
			i = parents[i];	
		}
		cout << 0 << "<- START\n";

	}
	
}


void mst_prims(int** G, int start, int const SIZE) {
	// prims algorithim 
	bool * mst = new bool[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		mst[i] = false;
	}
	Edge answer[SIZE-1];
	size_t mst_size = 0;
	mst_size++;
	pqueue<Edge> pq;
	for (size_t i = 0; i < SIZE; ++i) {
		if (G[start][i] != 0) {
			pq.enqueue(Edge(i,start,G[start][i]));
		}
	}
	mst[0] = true;
	size_t answer_count = 0;
	while (answer_count < SIZE && !pq.is_empty()) {
		Edge next_edge = pq.deque();
		//cout << "next edge: " << next_edge << '\n';
		int point_a = next_edge.point_a;
		int point_b = next_edge.point_b;
		int dist = next_edge.dist;
		if (!((mst[point_a] && !mst[point_b]) || (!mst[point_a] && mst[point_b]))) {
			continue;
		}
		answer[answer_count++] = next_edge;
		mst[point_a] = true;
		mst[point_b] = true;
		for (size_t i = 0; i < SIZE; ++i) {
			if (G[i][point_b] != 0) {
				//cout << point_b << " connects to " << i << '\n';
				pq.enqueue(Edge(i,point_b,G[i][point_b]));
			}
			if (G[i][point_a] != 0) {
				//cout << point_b << " connects to " << i << '\n';
				pq.enqueue(Edge(i,point_a,G[i][point_a]));
			}
		}
	}
	// sort, just to make debugging and comparing easier
	merge_sort(answer,SIZE-1);
	for (Edge each : answer) {
		cout << each << " ";
	}
	cout << '\n';
}

void mst_kruskal(int** G, int start, size_t const SIZE) {
	// kruskal's algorithm 
	int edges_size = 0;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			if (G[r][c] != 0) {
				edges_size++;
			}
		}
	}
	edges_size /=2;
	// init array
	Edge edges[edges_size];
	int count=0;
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			if (G[r][c] != 0) {
				edges[count++] = Edge(r,c,G[r][c]);
			}
			if (c == r) {
				break;
			}
		}
	}
	merge_sort(edges, edges_size);
	// keep adding edges to the mst as long as both verticies are not already connected
	WQUF u(SIZE);
	Edge* answer = new Edge[SIZE-1];
	int answer_count = 0;
	for (Edge & edge : edges) {
		int a = edge.point_a;
		int b = edge.point_b;
		int dist = edge.dist;
		if (!u.connected(a,b)) {
			answer[answer_count++] = edge;
		}
		u.combine(a,b);
		if (answer_count >= SIZE-1) {
			break;
		}
	}
	for (size_t i = 0; i < SIZE-1; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
}