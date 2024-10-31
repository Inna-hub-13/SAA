
// Assume there are N gifts. Each gift is represented by intger value, 
// stored in an array.
// Separate the gifts among two people, so that they have equal or almost equal
// value of presents.

// Dynamic programminc

#include <stdio.h>
#include <stdlib.h>
#define N 5

int sum(int*, int);
void separate_gifts(int*, int);

int main() {

    int gifts[N] = {3, 4, 5, 5, 1};
    separate_gifts(gifts, N);

    return 0;
}

int sum(int* arr, int size) {

    int sum = 0, i;

    for(i = 0; i < size; i++)
        sum += *(arr + i);
    
    return sum;
}

void separate_gifts(int* gifts, int size) {

    int total = sum(gifts, size);

    // sums -> represents all the possible sums of values of gifts
    // said in other words - all the possibilities to separate the gifts,
    // where 1 - there is such combination of gifts, 0 there is no such combination
    // each index of sums == sum 
    int* sums = (int*)malloc((total + 1) * sizeof(int));
    if(!sums)
        return;

    int i, j;
    *sums = 1;
    // initialize the rest of the sums array with zeros
    for(i = 1; i < total + 1; i++)
        *(sums + i) = 0;
    
    // starting from the end of the sums array
    // look for ones to make more combinations
    for(j = 0; j < size; j++)
        for(i = total; i >= 0; i--)
            if(*(sums + i) == 1)
                *(sums + i + *(gifts + j)) = 1;
    
    for(j = 0; j < total + 1; j++)
        printf("%d ", *(sums + j));

    // find the middle of sums array to seprate fairly
    j = total / 2;
    while(j == 0)
        j--;
    
    printf("\nGift value for the first %d\n", j);
    printf("Gift value for the seconds %d\n", total - j);
}
