
// Write a program that separates gifts among two people fairly.
// Assume the gifts have whole values and are stored in an array of integers.

// Somewhat upgraded version of Gifts.c - 07.11 2024

#include <stdio.h>
#include <stdlib.h>
#define N 5

int separate(int*, int, int*, int*);
int separate2(int*, int);

int main() {

    int gifts[N] = {3, 1, 2, 1, 2};
    int gift1, gift2;

    separate(gifts, N, &gift1, &gift2);
    printf("gift1: %d\n", gift1);
    printf("gift2: %d\n", gift2);

    separate2(gifts, N);

    return 0;
}

int separate(int* gifts, int gifts_size, int* gift1, int* gift2) {

    int sum = 0, i, j;

    for(i = 0; i < gifts_size; i++)
        sum += *(gifts + i);
    
    int* temp = (int*)calloc(sum + 1, sizeof(int));
    if(!temp)
        return - 1;
    
    *temp = 1;

    for(j = 0; j < gifts_size; j++) 
        for(i = sum; i >= 0; i--)
            if(*(temp + i) == 1)
                *(temp + i + *(gifts + j)) = 1;

    j = sum / 2;
    while(*(temp + j) == 0)
        j--;
    
    *gift1 = j;
    *gift2 = sum - j;
    return 0;
}

int separate2(int* gifts, int gifts_size) {

    int sum = 0, i, j;

    for(i = 0; i < gifts_size; i++)
        sum += *(gifts + i);
    
    int* temp = (int*)calloc(sum + 1, sizeof(int));
    if(!temp)
        return - 1;
    
    *temp = 1;

    for(j = 0; j < gifts_size; j++) 
        for(i = sum; i >= 0; i--)
            if(*(temp + i) != 0 && *(temp + i + *(gifts + j)) == 0)
                *(temp + i + *(gifts + j)) = *(gifts + j);

    j = sum / 2;
    while(*(temp + j) == 0)
        j--;
    
    printf("Gifts for the first: ");
    for(i = j; i > 0; i -= *(temp + i))
        printf("%d ", *(temp + i));
    
    printf("\n");
    printf("The other person gets the left gifts");
    return 0;
}

