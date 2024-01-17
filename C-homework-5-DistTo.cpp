#include <iostream>

struct DistTo {
	// creates a structure that tracks the distances between vertices
	int vertex;
	int accumulative_distance;
	DistTo() {
		vertex=-1;
		accumulative_distance=1000000;
	}
	DistTo(int v, int d) : vertex(v), accumulative_distance(d){}
	bool operator<(DistTo const& other) {
		return this->accumulative_distance < other.accumulative_distance;
	}	
	bool operator<=(DistTo const& other) {
		return this->accumulative_distance <= other.accumulative_distance;
	}	
};
