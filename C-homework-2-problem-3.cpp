// Alex Kramer 
// Homework 2
// Problem 3
// Testing Fibonacci Sequence
#include <iostream>

int F1(int n){ // function given in hw
    if (n == 0) return 1;
    return F1(n-1) + F1(n-1);
}

int F2(int n){ // function given in hw
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int result = F2(n / 2);
        return result * result;
    }
    else{
        return 2 * F2(n-1);
    }
}
void test_f1(int n, int expected){
    // function outputs what we are testing, expected results and the results
    std::cout << "Testing F1: n = " << n << "\n";
    std::cout << "Expected Results: " << expected << "\n";
    std::cout << "Results: " << F1(n) << "\n";
    std::cout << "\n";
}

void test_f2(int n, int expected){
     // function outputs what we are testing, expected results and the results
    std::cout << "Testing F2: n = " << n << "\n";
    std::cout << "Expected Results: " << expected << "\n";
    std::cout << "Results: " << F2(n) << "\n";
    std::cout << "\n";
}
int main(int argc, const char* argu[]){
     // using standard main call
     // main calls each testing function with several test cases
    int n = 2;
    test_f1(n,4);
    test_f2(n, 4);

    n = 4;
    test_f1(n,16);
    test_f2(n, 16);

    n = 8;
    test_f1(n,256);
    test_f2(n, 256);

    n = 16;
    test_f1(n,65536);
    test_f2(n, 65536);

    n = 24;
    test_f1(n,16777216);
    test_f2(n, 16777216);

    n = 30;
    test_f1(n,1073741824);
    test_f2(n, 1073741824);
}
