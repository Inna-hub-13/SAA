
// Implement Selection Sort

#include <stdio.h>

void selection_sort(double*, int);

int main() {

    double array[] = {1.2, 4, 1, -13, 2, 51, 12};
    int size = sizeof(array) / sizeof(double);
    int i;

    for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");

    selection_sort(array, size);
     for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");


    return 0;
}

void selection_sort(double* arr, int size) {

    int i, j, min_index;
    double temp;
    
    for(i = 0; i < size - 1; i++) {

        min_index = i;
        for(j = i + 1; j < size; j++)
            if(*(arr + min_index) > *(arr + j))
                min_index = j;
        
        // found min element in the unsorted part
        if(min_index != i) {

            temp = *(arr + i);
            *(arr + i) = *(arr + min_index);
            *(arr + min_index) = temp;
        }
    }
}
