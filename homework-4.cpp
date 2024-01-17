/// Alex Kramer 
/// Homework 4


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <chrono>
using namespace std;

//________________ CREATE ARRAY  ___________________________________
int * get_sorted() { // return a pointer to the array
    // BST case array
    static int array[1000]; // static pointing to the same place 
    for (int i =0; i < 1000; i++){
        array[i]=i;
    }
    return array; 
}

int * get_reverse(){
    // WST case array
    static int array[1000];
    for (int i = 1000 ; i > 0; i--){ // back fill 
        array[i]=1000-i;
    }
    return array;
}

int * get_random(){
    // AVG case array 
    static int array[1000];
    for (int i = 0; i < 1000; i++){
        array[i]= rand() % 100000;
    }
    return array;
}

void print_array(int const * const array, int const size){ // most restricted version of const 
    // print array
    for (int i =0; i < 1000; i++){
        cout << array[i] << '\n';
    }
}

// create global variables
int comps;
int moves;

//________________ SELECTION SORT ___________________________________
void selection_sort(int * const array, int const size){ 
    comps = 1; // last comparison will always fail so starting it at 1
    moves = 0;

    for (int i = 0; i < size; i++){ // looping through whole list
        comps ++; // for loop comparison 
        int min_value = array[i];
        int min_index = i;

        comps ++; // for loop comparison
        for (int j = i + 1; j <size; j++){ // looping through after to find minimum value
            comps ++; // if statement comparison
            if (array[j] < min_value){
                min_value = array[j];
                min_index = j;
            }
        }
        // if statement is due to an error when calculating moves 
        if (min_index == i){
            continue;
        }

        // swaping the values
        int temp = array[i];
        array[i] = array[min_index];
        moves ++;
        array[min_index] = temp;
        moves ++;
    }
}

//________________ BUBBLE SORT ___________________________________
void bubble_sort(int * const array, int const size){
    comps = 0; // won't fail on last run through
    moves = 0;

    bool changed = true;
    while (changed){ 
        changed = false;
        comps ++;
        for (int i = 0; i<size-1;i++){ // size -1 because looking at pairs 
            comps ++; // for loop comp
            comps ++; // if statement comp
            if (array[i] > array[i+1]){
                // then swap
                int temp = array[i];
                array[i] = array[i+1];
                moves ++;
                array[i+1] = temp;
                moves ++;
                changed = true; // flag for if we need to check it again 
            }
        
        }
    }    
}

//________________ INSERTION SORT ___________________________________
void insertion_sort(int * const array, int const size){ 
    // should be similar comps / moves to bubble sort
    comps = 1;
    moves = 0;
    for (int i=1; i < size;i++ ){ // i starts at 1 ( j will start at 0)
        comps ++;
        int key = array[i];
        int j = i-1;
        comps ++;
        while (j >= 0 and array[j]> key){ // 0 keeps us from out of bounds, if j > key then its out of order
            comps ++;
            array[j+1] = array[j]; // shifts the out order elemetn forward by one 
            moves ++;
            j--;
        }
        array[j+1] = key; // inserting the key in the correct place
        // technical this is a move but only if we make the move
    }
}

//________________ MERGE SORT ___________________________________
void merge(int * const A, int start, int mid, int end){
    int end_1 = mid - start;
    int end_2 = end - mid;
    // check to see if array is already sorted
    
    int L[end_1];
    int R[end_2];
    // get Left & Right array
    comps ++;
    for (int i=0; i < end_1; i++){
        L[i] = A[start + i]; // start at start - 1 for the offset
        moves ++;
        comps ++;
    }
    comps ++;
    for (int i=0; i< end_2; i++){
        R[i] = A[mid + i];
        moves ++;
        comps ++;
    }
    comps ++;
    if (L[end_1 - 1] <= R[0]){
        return;
    }
    int L_count = 0;
    int R_count = 0;
    int count = start; // position in array 
    comps ++;
    while (L_count < end_1 && R_count < end_2){
        comps ++;
        comps ++;
        if (L[L_count] < R[R_count]){
            A[count] = L[L_count]; // assign back to array
            moves ++;
            count ++;
            L_count ++;
        }
        else{
            A[count] = R[R_count]; // assign back to array
            count ++;
            moves ++;
            R_count ++;
        }
    }
    comps ++;
    while (L_count < end_1){
        comps ++;
        A[count] = L[L_count];
        count ++;
        moves ++;
        L_count ++;
    }
    comps ++;
    while (R_count < end_2){
        comps ++;
        A[count] = R[R_count];
        count ++;
        moves ++;
        R_count ++;
    }
}

void mergeSort(int * const array, int l, int r){
    comps ++;
    if (l < r-1){
        int m = (l+r) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m, r);
        merge(array, l, m, r);
    }

}
void merge_sort(int * const array, int size){
    // function to call merge sort (just to keep track of comps and moves)
    comps=0;
    moves=0;
    mergeSort(array, 0, size);

}

//________________ HEAP SORT ___________________________________
void heapify(int * const array, int const N, int i){
    // max heapify 

    int max = i; // puts max as root
    int l = 2 * i + 1; // l = 2*i + 1
    int r = 2 * i + 2; // r = 2*i + 2

    // l > root
  	comps++;
    if (l < N && array[l] > array[max])
        max = l;

    // r > root
  	comps++;
    if (r < N && array[r] > array[max])
        max = r;

    // if max is not root
  	comps++;
    if (max != i) {
        // swap is two moves
		int temp = array[i];
		array[i] = array[max];
		array[max] = temp;
      	moves+=2;

        // recursivly heapify to sort affected sub-trees
        heapify(array, N, max);
    }
}

void buildHeap(int * const array, int const size) { 
    // calls heapify on each level (which sorts every elemet)
	comps ++;
	for (int i = size; i >= 0; i--) { 
        comps ++;
		heapify(array,size, i); 
	} 
}

int pop_max(int * const array, int size) {
    // return max element 
	int ans = array[0];
	array[0] = array[size-1];
    moves ++;
	heapify(array,size, 0);
	return ans;
}

void heap_sort(int * const array, int const size){
    // takes aheap thats already sorted 
    moves = 0;
    comps = 0;

    buildHeap(array, size); // most expensive operation , puts array in heap-order O(nlog(n))
	int curr_size = size;
	int call_count = 0;
	int from_end = size-1;
    
    comps ++;
	while (call_count < size) {
        comps ++;
		array[from_end - call_count] = pop_max(array,from_end-call_count+1);
        moves ++;
		call_count++;
	}
}


//________________ QUICK SORT ___________________________________
int partition(int * const array, int start, int end) { 
    // 
    int pivot = array[start];
    int count = 0; // number of elements less than or equal to pivot
    comps ++;
    for (int i = start + 1; i <= end; i++) { 
        cout << i << " i\n";
        comps += 2;
        if (array[i] <= pivot) 
            count++;
    }
    // Giving pivot element its correct position
    int pivot_i = start + count; // starting at the correct index for the pivot

    int temp = array[pivot_i];
    array[pivot_i] = array[start];
    array[start] = temp;
    moves +=2;

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    comps ++;
    while (i < pivot_i && j > pivot_i) {
        comps +=2;
        while (array[i] <= pivot) {
            i++; // find out of order elements (left side)
            comps ++;
        }
        comps ++;
        while (array[j] > pivot) { // find out of order elements (right side)
            j--; //
            comps ++;
        }
        comps ++;
        if (i < pivot_i && j > pivot_i) { // swap them if they are out of order
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j --;
            moves += 2;        
        }
    }
    return pivot_i;
}
 
void quickSort(int * const array, int start, int end)
{
    // base case
    comps ++;
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(array, start, end);
    // left part
    quickSort(array, start, p - 1);
    // right part
    quickSort(array, p + 1, end);
}

void quick_sort(int * const array, int size){
	moves = 0;
	comps = 0;
  	quickSort(array, 0, size - 1);
}

// ________Write File____________
void write_file(ofstream & file, string function, string array){ //function = function name; array = array name (bst, wst, avg)
    file << function << "," << array << "," << comps << "," << moves << "\n"; 
}

int main() {
    ofstream file("stats.csv");
    // open file to write to 

    // create base arrays 
    int * best = get_sorted();
    int * worst = get_reverse();
    int * avg = get_random();

    /*
    // SELECTION SORT
    selection_sort(avg, 1000); // selection sort has no really difference comps = n^2, moves = n
    write_file(file, "Selection Sort", "Avg");

    selection_sort(best, 1000);
    write_file(file, "Selection Sort", "Bst");

    selection_sort(worst, 1000);
    write_file(file, "Selection Sort", "Wst");
    
    // reassigning arrays so we are not feeding all sorted arrays to the sorting algorithms
    best = get_sorted();
    worst = get_reverse();
    avg = get_random();
    
    // BUBBLE SORT
    bubble_sort(avg, 1000);
    write_file(file, "Bubble Sort", "Avg");
    bubble_sort(best, 1000);
    write_file(file, "Bubble Sort", "Bst");
    bubble_sort(worst, 1000);
    write_file(file, "Bubble Sort", "Wst");
    
    best = get_sorted();
    worst = get_reverse();
    avg = get_random();

    // INSERTION SORT
    insertion_sort(avg, 1000);
    write_file(file, "Insertion Sort", "Avg");
    insertion_sort(best, 1000);
    write_file(file, "Insertion Sort", "Bst");
    insertion_sort(worst, 1000);
    write_file(file, "Insertion Sort", "Wst");
    
    best = get_sorted();
    worst = get_reverse();
    avg = get_random();
    
    // MERGE SORT
    merge_sort(avg, 1000);
    write_file(file, "Merge Sort", "Avg");
    merge_sort(best, 1000);
    write_file(file, "Merge Sort", "Bst");
    merge_sort(worst, 1000);
    write_file(file, "Merge Sort", "Wst");
    
    best = get_sorted();
    worst = get_reverse();
    avg = get_random();

    // HEAP SORT
    heap_sort(avg, 1000);
    write_file(file, "Heap Sort", "Avg");
    heap_sort(best, 1000);
    write_file(file, "Heap Sort", "Bst");
    heap_sort(worst, 1000);
    write_file(file, "Heap Sort", "Wst");
    
    best = get_sorted();
    worst = get_reverse();
    avg = get_random();
    */
    // QUICK SORT
    quick_sort(avg, 100);
    cout << avg;
    write_file(file, "Quick Sort", "Avg");
    quick_sort(best, 100);
    write_file(file, "Quick Sort", "Bst");
    quick_sort(worst, 100);
    write_file(file, "Quick Sort", "Wst");

    // close file
    file.close();
}