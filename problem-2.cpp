// Alex Kramer 
// Homework 2
// Problem 2 
// Merge Sort

#include <cstdlib>
#include <iostream>
#include <random>

void merge(int A[], int start, int mid, int end){
    int end_1 = mid - start;
    int end_2 = end - mid;
    // check to see if array is already sorted

    int L[end_1];
    int R[end_2];
    // get Left & Right array
    for (int i=0; i < end_1; i++){
        L[i] = A[start + i]; // start at start - 1 for the offset
    }
    for (int i=0; i< end_2; i++){
        R[i] = A[mid + i];
    }
    if (L[end_1 - 1] <= R[0]){
        return;
    }
    int L_count = 0;
    int R_count = 0;
    int count = start; // position in array 
    while (L_count < end_1 && R_count < end_2){
        if (L[L_count] < R[R_count]){
            A[count] = L[L_count]; // assign back to array
            count ++;
            L_count ++;
        }
        else{
            A[count] = R[R_count]; // assign back to array
            count ++;
            R_count ++;
        }
    }
    while (L_count < end_1){
        A[count] = L[L_count];
        count ++;
        L_count ++;
    }
    while (R_count < end_2){
        A[count] = R[R_count];
        count ++;
        R_count ++;
    }

}

void merge_sort(int A[], int start, int end){
    if (start >= end -1 ){return;}
    int mid = ((start + end) / 2);
    merge_sort(A,  start, mid);
    merge_sort(A, mid,  end);
    merge(A, start, mid, end);
}
void print_array(const int A[], const int size){
    for (int i = 0; i < size; i++){
        std::cout << A[i] << '\n';
    }
}
int main(){
    int A[30];
    for (int i = 0; i < 30; i++){
        A[i] = rand() % 100;
    }
    // print_array(A, 30);
    merge_sort(A, 0, 30);
    print_array(A, 30);

}