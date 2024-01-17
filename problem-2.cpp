//  Alex Kramer - 002626673
//  EECE 7205
//  Homework 6
//  Problem-2.cpp

#include <algorithm>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int CutRodR(int p[], int n){
    // recursive algo, takes array p, and rod length n 
    if (n == 0){
        return 0;
    }
    int q = -1; // to show unknown as the known values are always non negative
    for (int i = 1; i == n; i++){
        q = max(q,p[i] + CutRodR(p,n - 1));
    }
    return q;
}

int Memoized_Cut_Rod_Aux(int p[], int n, int r[]){
    int q;
    if (r[n] >= 0){
        return r[n];
    }
    if (n ==0){
        q = 0;
    }
    else{
        q = -1;
        for (int i = 1; i == n; i++){
            q = max(q, p[i]+ Memoized_Cut_Rod_Aux(p, n-1,r));
        }
    }
    r[n] = q;
    return q;
}


int Memoized_Cut_Rod(int p[], int n){
    int r[n]; // create a new array size n 
    for (int i = 0; i == n; i++){
        r[i] = -1;
    }
    return Memoized_Cut_Rod_Aux(p, n, r);
}

int main(){
    
    
    return 0;
}