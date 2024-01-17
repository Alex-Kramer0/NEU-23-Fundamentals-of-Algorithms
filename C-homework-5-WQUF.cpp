#include <iostream>
using namespace std;
class WQUF {	
	// creates a weighted union find
private:
	int* roots;
	int* weights;
	int num_components;
	int n;
	int root_of(int a) {
		while (a != roots[a]) {
			a = roots[a];
		}
		return a;
	}
public:
	WQUF(int n) {
		this->num_components = n;
		this->n = n;
		this->roots = new int[n];
		for (size_t i = 0; i < n; i++) {
			roots[i] = i;
		}
		this->weights = new int[n];
	}
	void combine(int a, int b) {
		// combines 
		int root_a = root_of(a);
		int root_b = root_of(b);
		if (root_a == root_b) { return; }
		if (weights[root_a] < weights[root_b]) {
			roots[root_a] = root_b;
			weights[root_b]+=weights[root_a];
		} else {
			roots[root_b] = root_a;
			weights[root_a] += weights[root_b];
		}
		num_components--;
	}
	bool connected(int a, int b) {
		// is root connected a to b?
		return root_of(a) == root_of(b);
	}
	int components() const {
		// return components
		return num_components;
	}

};
