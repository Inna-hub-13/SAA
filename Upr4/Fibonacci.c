
// Find the nth Fibonacci number. 
// Implementation of iterative algorithm.
// Implementation of recursive algorithm.

// Added time checking for both solutions - 07.11 2024

// 1 1 2 3 5 8 13...

#include <stdio.h>
#include <time.h>

int find_fib(int);
int find_fib_r(int);

int main() {

    int n;
    clock_t start, end;

    for(n = 10; n <= 45; n += 5){

        start = clock();
        printf("find_fib(%d): %d\n", n, find_fib(n));
        end = clock();
        printf("Time iteration: %lf sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        start = clock();
        printf("find_fib_r(%d): %d\n", n, find_fib_r(n));
        end = clock();
        printf("Time recurtion: %lf sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        printf("\n");
    }

    return 0;
}

int find_fib(int n) {

    int i, f = 1, f1 = 1, f2 = 1;
    for(i = 2; i <= n; i++) {
        
        f = f1 + f2;
        f1 = f2;
        f2 = f; 
    }

    return f;
}

int find_fib_r(int n) {

    if(n <= 1)
        return 1;

    return find_fib_r(n - 1) + find_fib_r(n - 2);
}
