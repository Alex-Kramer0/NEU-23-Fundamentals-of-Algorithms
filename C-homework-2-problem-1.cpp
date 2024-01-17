// Alex Kramer 
// Homework 2
// Problem 1 
// Merge Sort 

#include <cstdlib>
#include <iostream>
#include <random>

void merge(int A[], int start, int mid, int end){
    // from pseudo code
    // function merges two lists based on element values
    
    int end_1 = mid - start;
    int end_2 = end - mid;
    // end 1 & end 2 are used to create the dimensions of our sub arrays


    if (A[mid - 1]<= A[mid]){return;} 
    // check to see if array is already sorted

    int L[end_1];
    int R[end_2];
    // create Left & Right subarray
    
    for (int i=0; i < end_1; i++){// start at start - 1 for the offset
        L[i] = A[start + i]; 
        // give left list the starting postion through the mid postion
        // values in our starting arrray 
        // this is just creating our sub array
    }
    for (int i=0; i< end_2; i++){
        R[i] = A[mid + i];
        // same comments as above, except from mid point to end of array
    }

    int L_count = 0;
    int R_count = 0;
    int count = start; 
    // position in array 
    
    while (L_count < end_1 && R_count < end_2){ // while within Left and Righ sub array make a comparison
                                                // then assign smallest item to next pos in array A
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

    while (L_count < end_1){ // acount for sentianl, basically if left still has more in the subarray
                            // add the rest to the original array A
        A[count] = L[L_count];
        count ++;
        L_count ++;
    }

    while (R_count < end_2){ // same as above but for right 
        A[count] = R[R_count];
        count ++;
        R_count ++;
    }

}

void merge_sort(int A[], int start, int end){
    // merge sort function calling (driver for our merge)
    if (start >= end -1 ){return;}
    int mid = ((start + end) / 2);
    merge_sort(A,  start, mid);
    merge_sort(A, mid,  end);
    merge(A, start, mid, end);
}
void print_array(const int A[], const int size){
    // print the array
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
