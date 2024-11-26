
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void selection_sort(float*, int);
void insertion_sort(float*, int);
void bubble_sort(float*, int);
void bubble_sort_flag(float*, int);
int* counting_sort(int*, int);
void quick_sort(float*, int, int);

void fill_random(float*, int);
void compare_algorithms(FILE*);

int main() {

    FILE *file;
    file = fopen("times.txt", "w");
    if(!file)
        return -1;
    compare_algorithms(file);
    fclose(file);

    return 0;
}

void fill_random(float* arr, int size){

    int i;
    srand(time(0));
    for(i = 0; i < size; i++)
        *(arr + i) = rand();
}

void selection_sort(float* arr, int size) {

    int i, j, min_index;
    float temp;

    for(i = 0; i < size - 1; i++) {

        min_index = i;
        for(j = i + 1; j < size; j++)
            if(*(arr + min_index) > *(arr + j))
                min_index = j;

        // found min element
        if(min_index != i) {

            temp = *(arr + min_index);
            *(arr + min_index) = *(arr + i);
            *(arr + i) = temp;
        }
    }
}

void insertion_sort(float* arr, int size) {

    int i, j;
    float temp;

    for(i = 0; i < size - 1; i++) {

        j = i + 1;
        temp = *(arr + j);
        while(j > 0 && *(arr + j - 1) > temp){

            *(arr + j) = *(arr + j - 1);
            j--;
        }

        *(arr + j) = temp;

    }
}

void bubble_sort(float* arr, int size) {

    int i, j;
    float temp;

    for(i = 0; i < size - 1; i++) {

        for(j = size - 1; j > i; j--){

            if(*(arr + j) < *(arr + j - 1)){

                temp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = temp;
            }
        }
    }
}

void bubble_sort_flag(float* arr, int size) {

    int i, j, flag;
    float temp;

    for(i = 0; i < size - 1; i++) {

        flag = 0;
        for(j = size - 1; j > i; j--){

            if(*(arr + j) < *(arr + j - 1)){

                temp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = temp;
                flag = 1;
            }
        }

        // break for loop, because all the elems are sorted 
        if(flag == 0)
            i = size;
    }
}

int* counting_sort(int* arr, int size) {

    int i, max = *arr;
    for(i = 1; i < size; i++)
        if(*(arr + i) > max)
            max = *(arr + i);
    
    int* count_arr = (int*)calloc(max + 1, sizeof(int));
        if(!count_arr)
            return NULL;
    
    for(i = 0; i < size; i++)
        (*(count_arr + *(arr + i)))++;
        
    // store prefix sum to help you place the elements in the output array
    for(i = 1; i < max + 1; i++)
        *(count_arr + i) = *(count_arr + i) + *(count_arr + i - 1);

    int* output = (int*)malloc(size * sizeof(int));

    for(i = size - 1; i >= 0; i--){

        *(output + (*(count_arr + *(arr + i))) - 1) = *(arr + i);
        (*(count_arr + *(arr + i))) --;
    }

    return output;

}

void quick_sort(float* arr, int start, int stop) {

    int i = start, j = stop;
    float temp, m;
    m = *(arr + (start + stop) / 2);
    do{

        while(*(arr + i) < m)i++;
        while(*(arr + j) > m)j--;
        if(i <= j){

            temp = *(arr + j);
            *(arr + j) = *(arr + i);
            *(arr + i) = temp;
            i++;
            j--;
        }
    }while(i <= j);

    if(j > start)
        quick_sort(arr, start, j);
    if(i < stop)
        quick_sort(arr, i, stop);

}

void compare_algorithms(FILE* file){

    int n = 1000;
    float t1, t2;

    float *arr1, *arr2, *arr3, *arr4, *arr5;
    do{

        fprintf(file, "\nFor %d elements\n", n);
        arr1 = (float*)malloc(n * sizeof(float));
        if(!arr1)
            return;
        fill_random(arr1, n);
        t1 = GetTickCount();
        selection_sort(arr1, n);
        t2 = GetTickCount();
        fprintf(file, "Selection Sort time: %f\n", t2 - t1);


        arr2 = (float*)malloc(n * sizeof(float));
        if(!arr2)
            return;
        fill_random(arr2, n);
        t1 = GetTickCount();
        insertion_sort(arr2, n);
        t2 = GetTickCount();
        fprintf(file, "Insertion Sort time: %f\n", t2 - t1);

        arr3 = (float*)malloc(n * sizeof(float));
        if(!arr3)
            return;
        fill_random(arr3, n);
        t1 = GetTickCount();
        bubble_sort(arr3, n);
        t2 = GetTickCount();
        fprintf(file, "Bubble Sort time: %f\n", t2 - t1);

        arr4 = (float*)malloc(n * sizeof(float));
        if(!arr4)
            return;
        fill_random(arr4, n);
        t1 = GetTickCount();
        bubble_sort_flag(arr4, n);
        t2 = GetTickCount();
        fprintf(file, "Bubble Sort Flag time: %f\n", t2 - t1);

        arr5 = (float*)malloc(n * sizeof(float));
        if(!arr5)
            return;
        fill_random(arr5, n);
        t1 = GetTickCount();
        bubble_sort_flag(arr5, n);
        t2 = GetTickCount();
        fprintf(file, "Quick Sort time: %f\n\n", t2 - t1);

        printf("Enter array size: ");
        scanf(" %d", &n);
    }while(n);

}

