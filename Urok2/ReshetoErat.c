
// Write a program that finds all prime numbers 
// smaller or equal to given n

// Implementation of Sieve of Eratosthenes

// Assume every index of array corresponds to the value, represented by the index
// Assume 1 - composite, 0 - prime

#include <stdio.h>
#define N 100

int array[N];

void initialize_arr(int);
void find_primes(int);

int main() {

    initialize_arr(N);
    find_primes(50);

    return 0;
}

// First, we assume all numbers are prime - add zeros to array
void initialize_arr(int size) {

    for(int p = 0; p < size; p++) 
        *(array + p) = 0;
}

void find_primes(int n) {

    int i, j;

    for(i = 2; i <= n; i++){

        if(*(array + i) == 0){
            
        j = i*i;

        while(j <= n){

            *(array + j) = 1;
            j += i; 
        }
        }  
    }

    printf("\nPrimes <= %d\n", n);

    for(i = 2; i <= n; i++)
        if(*(array + i) == 0)
            printf("%-4d ", i);
    
    printf("\n");
}
