
// Implementation of Bubble Sort

#include <stdio.h>

void bubble_sort(double*, int);

int main() {

    double array[] = {1.2, 40, 1, 13, 2, -51, 12};
    int size = sizeof(array) / sizeof(double);
    int i;

    for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");

    bubble_sort(array, size);
     for(i = 0; i < size; i++)
        printf("%.2lf\t", *(array + i));
    
    printf("\n");


    return 0;
}

void bubble_sort(double* arr, int n) {

    int i, j, flag;
    double temp;

    for(i = 0; i < n - 1; i++){
        
        flag = 0;
        for(j = n - 1; j > i; j--){

            if(*(arr + j) < *(arr + j - 1)){

                temp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = temp;
                flag = 1;
            }
        }

        // the array is already sorted
        if(!flag)
            break;
    }
}

