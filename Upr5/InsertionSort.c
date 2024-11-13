
// Implement Insertion Sort

#include <stdio.h>

void insertion_sort(double*, int);

int main() {

    double array[] = {1.2, 4, 1, -13, 2, 51, 12};
    int size = sizeof(array) / sizeof(double);
    int i;

    for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");

    insertion_sort(array, size);
     for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");


    return 0;
}

void insertion_sort(double* arr, int n) {

    int i, j;
    double temp;
    
    for(i = 1; i < n; i++) {

        j = i;
        temp = *(arr + j);
        while(*(arr + j - 1) > temp && j > 0) {

            *(arr + j) = *(arr + j - 1);
            j--;
        }

        *(arr + j) = temp;
    }
}
