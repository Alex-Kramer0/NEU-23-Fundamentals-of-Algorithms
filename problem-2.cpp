//  Alex Kramer - 002626673
//  EECE 7205
//  Homework 1 
//  Problem-2.cpp
//

#include <iostream>

void MinFirst(int v[], int n)
{
    // Set the first value as the minimum
    int min = v[0];
    int min_index = 0;
    
    // Find the index of minimum value
    for (int i = 1; i < n; i++){
        if (v[i] < min){
            min = v[i];
            min_index = i;
        }
    }
    // Move the min value to position 0
    if (min_index != 0){
        for (int a = min_index; a > 0; a--){
            v[a] = v[a-1];
        }
        v[0] = min;
    }
}

int main()
{
    std::cout<<"\n";
    // Problem 2
    // Declare array
    int v[] = {6, 2, 7, 8, 1, 5};
    
    std::cout<<"Printing original array: ";
    for (int i = 0; i < 6; i++)
        std::cout << v[i] <<' ';

    // Bring Min value to beginning
    MinFirst(v, 6);
    std::cout<<"\n";
    std::cout<<"Testing MinFirst Function\n\n";
    std::cout<<"Expected Results: 1 6 2 7 8 5\n";
    std::cout<<"Results: ";
    // Print array
    for (int i = 0; i < 6; i++)
        std::cout << v[i] <<' ';
    return 0;
}