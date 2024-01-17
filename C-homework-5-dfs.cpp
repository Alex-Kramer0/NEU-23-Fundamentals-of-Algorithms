#include <iostream>
using namespace std;
class list { 
	// create linked list structure
	private:
		struct node {
		int val;
		node* next;
		node(int v) {
			val = v;
		}
	};
	node* head;
	public:
	list() {
		head = nullptr;
	}
	void push(int v) { // create push
		node* new_head = new node(v);
		new_head->next = head;
		head = new_head;
	}
	int pop() { // create pop
		int ret = head->val;
		node* old_head = head;
		head = head->next;
		delete old_head;
		return ret;
	}
	bool is_empty() { // is empty?
		return head == nullptr;
	}
};

void dfs(int v, int** matrix, size_t const SIZE) {
	// create depth first search 
	bool * seen = new bool[SIZE];
	list s;
	s.push(v); // empty stack
	while (!s.is_empty()) { // when stack is empty
		int next_vertex = s.pop(); // add each adjaceny vertex
		if (seen[next_vertex]) {
			continue;
		}
		seen[next_vertex] = true; // mark visted as seen 
		for (size_t i = 0; i < SIZE; i++) {
			if (matrix[next_vertex][i] != 0) {
				s.push(i); 
			}
		}
	}
	for (size_t i = 0; i < SIZE; i++) {
		if (!seen[i]) { // if any vertex is unvisited after visting all neighbors
			cout << "Not connected to: " << i << '\n'; // print not connected error
			throw int();
		}
	}
	cout << "Graph is connected\n";
}
