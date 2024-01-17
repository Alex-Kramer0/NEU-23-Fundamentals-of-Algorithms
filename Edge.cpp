#include <iostream>
using namespace std;
struct Edge {
	// creates edge structure
	int point_a;
	int point_b;
	int dist;
	Edge() {
		this->point_a = -1;
		this->point_b = -1;
		this->dist = 10000000;
	}
	Edge(int a, int b, int d) {
		this->point_a = a;
		this->point_b = b;
		this->dist = d;
	}
	bool operator<(Edge const& other) { 
		return this->dist < other.dist;
	}
	bool operator<=(Edge const& other) {
		return this->dist <= other.dist;
	}
	friend ostream& operator<<(ostream& os, Edge const& e) {
		os << "Edge(" << e.point_a << "," << e.point_b << "," << e.dist << ")";
		return os;
	}

};
