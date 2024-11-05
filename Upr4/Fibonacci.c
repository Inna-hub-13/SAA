
// Find the nth Fibonacci number. 
// Implementation of iterative algorithm.

// 1 1 2 3 5 8 13...

#include <stdio.h>

int find_fib(int);

int main() {

    int n1 = find_fib(3);
    int n2 = find_fib(8);
    int n3 = find_fib(7);

    printf("find_fib(3): %d\n", n1);
    printf("find_fib(8): %d\n", n2);
    printf("find_fib(7): %d\n", n3);

    return 0;
}

int find_fib(int n) {

    int i, f = 1, f1 = 1, f2 = 1;
    for(i = 2; i < n; i++) {
        
        f = f1 + f2;
        f1 = f2;
        f2 = f; 
    }

    return f;
}
