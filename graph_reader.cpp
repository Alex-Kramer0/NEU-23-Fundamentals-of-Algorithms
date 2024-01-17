#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void print_graph(int** matrix, size_t SIZE) {
	// print graph function
	for (size_t r = 0; r < SIZE; r++) {
		for (size_t c = 0; c < SIZE; c++) {
			cout << matrix[r][c] << '\t';
		}
		cout << '\n';
	} 
}
int** init_matrix(size_t SIZE) {
	// initialize matrix function
	int** matrix = new int*[SIZE];
	for (size_t i = 0; i < SIZE; ++i) {
		matrix[i] = new int[5];
	}
	return matrix;
}
int** read_graph(string file_name, int& SIZE) {
	// read graph in from file function
	ifstream in(file_name);
	size_t n;
	in >> n;
	SIZE = n;
	int** matrix = init_matrix(SIZE);
	size_t r = 0;
	while (!in.eof()) {
		for (size_t c = 0; c < SIZE; c++) {
			in >> matrix[r][c];
		}	
		r++;
	}
	return matrix;
}