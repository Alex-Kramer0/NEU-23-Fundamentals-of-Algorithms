//  Alex Kramer
//  EECE 7205
//  Homework 6
//  Problem-1.cpp

#include <iostream>
#include <fstream>
using namespace std;

int A[50]; // created global array for dynamic memory allocation 
// not sure how to not hard code this size in?

int FibonacciR(int n){
    // finds the nth number in the fibonacci sequence
    // takes n,
    if (n <= 1){
        return n;
    }
    return FibonacciR(n-1) + FibonacciR(n-2);
}

int FibonacciD(int n){
    // finds the nth number in the fibonacci sequence
    // takes n, uses dynamic memory
    if (n <= 1){ 
        // if n = 0 or 1 return n
        return n;
    }
    else if (A[n] != -1) {
        // elif n is already in our dynamic array return n 
        // no need to recalculate what is already in the array
        return A[n];
    }
    A[n]= FibonacciD(n-1) + FibonacciD(n-2);
    // if n is not already solved in the array, solve n

    return A[n];
}

int main(){
    int n; // the user inputs this number to calculate its Fibonacci sequence
    cout << "n = ";
    cin >> n;
    cout << "\n";
    // initialize all elements in array A to an invalid ibonacci value 
    for (int i =0; i <= n; i++){
        A[i] = -1;
    }

    // find fibonacci sequence n using recursive function
    cout << "FibonacciR(n) = " << FibonacciR(n) << "\n\n";

    // find fibonacci sequence n using dyanmic programming funcyion
    cout << "FibonacciD(n) = " << FibonacciD(n) << "\n";;

    return 0;
}
