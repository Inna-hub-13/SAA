
// Write a program that counts elements in 
// an unsorted array of natural numbers in range 0 - 10
// Loop through the array only once

#include <stdio.h>
#include <stdlib.h>
#define N 11

void print_arr(int*, int);
void fill_arr(int*, int, int);
int* count_elements(int*, int);
int max_el(int*, int);
int min_el(int*, int);
void count_sort(int*, int*, int);

int main() {

    int array[] = {8, 1, 8, 8, 8, 1, 2, 2, 2, 5, 9};
    int size = sizeof(array) / sizeof(int);

    print_arr(array, size);
    int* count_el = count_elements(array, size);

    printf("min_el = %d\n", min_el(count_el, N));
    printf("max_el = %d\n", max_el(count_el, N));

    printf("Count arr:\n");
    print_arr(count_el, N);

    printf("After count_sort\n");
    count_sort(count_el, array, N);
    print_arr(array, size);


    printf("Count arr:\n");
    print_arr(count_el, N);
    return 0;
}

void print_arr(int* arr, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    
    printf("\n");
}

void fill_arr(int* arr, int size, int num) {

    for(int i = 0; i < size; i++)
        *(arr + i) = num;
}

int* count_elements(int* arr, int size) {

    int* count_el = (int*)malloc(N * sizeof(int));

    if(!count_el)
        return NULL;

    fill_arr(count_el, N, 0);

    int i;
    for(i = 0; i < size; i++)
        // count_el[arr[i]] ++;
        (*(count_el + *(arr + i))) ++;

    for(i = 0; i < N; i++)
        if(*(count_el + i) != 0)
            printf("%d -> %d\n", i, *(count_el + i));


    return count_el;
}


// finding max_el and min_el, using the array, that stores the count of elements
int max_el(int* arr, int size) {

    for(int i = size - 1; i >= 0; i--)
        if(*(arr + i) != 0)
            return i;
    
    // no counted elements, input array must have been empty
    return -1;
}

int min_el(int* arr, int size) {

    for(int i = 0; i < size; i++)
        if(*(arr + i) != 0)
            return i;

    // no counted elements, input array must have been empty
    return -1;
}

void count_sort(int* count_arr, int* arr, int size_count_arr) {

    // j -> index of unsorted arr
    int i, j, temp;
    for(i = 0, j = 0; i < size_count_arr; i++) {

        temp = 0;
        while(temp < *(count_arr + i)){
            *(arr + j) = i;
            j++;
            temp++;
        }

        // changing actual count_arr!
       /* while(*(count_arr + i) != 0){
            *(arr + j) = i;
            j++;
            (*(count_arr + i))--;
        }
        */
    }
}
