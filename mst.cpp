// not included

#include "merge_sort.cpp"
#include "WQUF.cpp"
#include "pqueue.cpp"
using namespace std;

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
	Edge edges[edges_size] {};
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