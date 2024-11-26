#include <stdio.h>
#define N 20

int slow_search(int*, int, int);
int slow_search2(int*, int, int);
void quick_sort(int*, int, int);
int binary_search(int*, int, int);

int main() {

    int arr[N] = {1, 13, -3, 4, 5, 7, 18};

    int i;
    for(i = 0; i < 7; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    printf("slow_search(arr, 12, 7) returned: %d\n", slow_search(arr, 12, 7));
    printf("slow_search(arr, 13, 7) returned: %d\n\n", slow_search(arr, 13, 7));
    
    printf("slow_search2(arr, 13, 7) returned: %d\n", slow_search2(arr, 13, 7));
    printf("slow_search2(arr, 18, 7) returned: %d\n", slow_search2(arr, 18, 7));
    printf("slow_search2(arr, 1, 7) returned: %d\n\n", slow_search2(arr, 1, 7));
    
    quick_sort(arr, 0, 6);
    for(i = 0; i < 7; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    printf("binary_search(arr, 18, 7) returned: %d\n\n", binary_search(arr, 18, 7));

    return 0;
}

// 2n comparisons, O(n)
int slow_search(int* arr, int key, int size) {

    int i;
    for(i = 0; i < size; i++)
        if(*(arr + i) == key)
            return i;

    return -1;
}

// *we assume the array can take the expansion
// n + 1 comparisons, O(n)
int slow_search2(int* arr, int key, int size) {

    *(arr + size) = key;
    int i = 0;

    while(*(arr + i) != key)
        i++;
    
    if(i != size)
        return i;
    
    return -1;
}

void quick_sort(int* arr, int start, int stop) {

    int i = start, j = stop, m, temp;
    m = (start + stop) / 2;
    do{

        while(*(arr + i) < *(arr + m)) i++;
        while(*(arr + j) > *(arr + m)) j--;
        if(i <= j){

            temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp; 
            i++;
            j--;
        }
    }while(i <= j);

    if(j > start)
        quick_sort(arr, start, j);
    if(i < stop)
        quick_sort(arr, i, stop);
}

// logn comparisons, O(logn)
int binary_search(int* arr, int key, int size) {

    int l = 0, r = size - 1, m;
    
    while(l <= r){

        m = (l + r) / 2;
        if(*(arr + m) > key)
            r = m - 1;
        else
            if(*(arr + m) < key)
                l = m + 1;
            else
                return m;
    }

    return -1;
}
