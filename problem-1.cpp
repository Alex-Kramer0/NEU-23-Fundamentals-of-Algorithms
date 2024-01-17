//  Alex Kramer - 002626673
//  EECE 7205
//  Homework 1 
//  Problem-1.cpp
//

#include <iostream>

void SwapP(int *a, int *b)
{
    // SwapP swaps the values of two integer variables using pass-by-pointer
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SwapR(int &a, int &b)
{
    //SwapR swaps the values of two integer variables using pass-by-reference
    int temp = a;
    a = b;
    b =  temp;
}

int main()
{
    // Test SwapP
    std::cout<<"\n";
    int a = 10;
    int b = 23;
    SwapP(&a, &b);
    std::cout<<"A = 10\n";
    std::cout<<"B = 23\n";
    std::cout<<"\n";
    std::cout<<"Testing SwapP\n";
    std::cout<<"Expected Results: a = 23, b = 10\n";
    std::cout<<"Results: a = "<< a<< ", b = "<< b<<"\n";
    std::cout<<"\n";
    // Test SwapR
    int x = 10;
    int y = 23;
    SwapR(x, y);
    std::cout<<"X = 10\n";
    std::cout<<"Y = 23\n";
    std::cout<<"\n";
    std::cout<<"Testing SwapR\n";
    std::cout<<"Expected Results: x = 23, y = 10\n";
    std::cout<<"Results: x = "<< x<< ", y = "<< y<<"\n";
}