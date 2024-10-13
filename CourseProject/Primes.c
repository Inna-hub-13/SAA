
// Write a program that finds all primes <= n
// Find the max number of variations of primes
// V (k over n) = n! / (n - k) ! 
// Ex. 23, 32, 25, 52, 172, 192 ...


// Implementation of Sieve of Eratosthenes

// !!indices correspond to the actual values
// 1 is composite, 0 is prime

#include <stdio.h>
#include <stdlib.h>

int find_primes(int);
void fill_arr(int*, int, int);
int cal_variation(int, int);

int main() {

    int count_primes = find_primes(50);
    printf("number of primes = %d\n", count_primes);

    printf("number of variations of primes = %d\n", cal_variation(2, count_primes));
    
    return 0;
}

void fill_arr(int* arr, int size, int num) {

    for(int i = 0; i < size; i++)
        *(arr + i) = num;
}

int find_primes(int n) {

    int i, j, count_primes = 0;

    int* sieve = (int*)malloc((n + 1) * sizeof(int));

    if(sieve == NULL)
        return -1;

    // first, assume all numbers are prime
    fill_arr(sieve, n + 1, 0);

    for(i = 2; i <= n; i++) {

        if(*(sieve + i) == 0) {

            printf("%-4d ", i);
            j = i*i;
            count_primes++;

            while(j <= n){
                *(sieve + j) = 1;
                j += i;
            }
        }
    }
    printf("\n");

    return count_primes;
}

int cal_variation(int k, int n) {

    int v = 1;
    for(int i = n; i > n - k; i--) 
        v *= i;

    return v;
}

