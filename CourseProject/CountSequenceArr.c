
// Assume we have an array of integers and for some of its elements
// ai <= ai+1 <= ai+2 ...

// 1) find the size of longest such sequence
// 2) find the start and the end indices of the sequence
// 3) swap the elements of the sequence

#include <stdio.h>
#include <stdlib.h>
#define N 13

void print_arr(int*, int);
int* count_longest_sequence(int*, int);
void swap_elements(int*, int, int);

int main() {

    int arr[N] = {11, 4, 5, 6, 7, 9, 16, 18, 100, 1, 2, 3, 13};
    int* count_longest = count_longest_sequence(arr, N);

    printf("\nCounted longest sequene, count = %d\n", count_longest[0]);
    printf("start index = %d\n", count_longest[2]);
    printf("end index = %d\n", count_longest[1]);
    print_arr(arr, N);

    printf("\nAfter swap\n");
    swap_elements(arr, count_longest[2], count_longest[1]);
    print_arr(arr, N);


    return 0;
}

void print_arr(int* arr, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

int* count_longest_sequence(int* arr, int size) {

    // Return array answer[]
    // answer[0] is equivalent to max_count
    // answer[1] is equivalent to index_end
    // answer[2] is equivalent to index_start
    // *only track index_end, index_start = index_end - max_count + 1;

    int* answer = (int*)malloc(3*sizeof(int));
    if(answer == NULL)
        return NULL;

    // count_elements -> elements which meet the condition
    int count_elements = 1;
    
    answer[0] = 0;
    answer[1] = 0;

    for(int i = 0; i < size - 1; i++){

        if(*(arr + i) <= *(arr + i + 1))
            count_elements++;

        else{

            if(count_elements > answer[0]){
                
                answer[0] = count_elements;
                answer[1] = i;
            }

            count_elements = 1;
        }
    }

    // *skipped <else> in last iteration of for loop
    // -> that means we must have had a squence
    // (right before the termination of for loop)
    // in which the elements meet the condition
     if(count_elements > answer[0]){

         answer[0] = count_elements;
         answer[1] = size - 1;
     }

     answer[2] = answer[1] - answer[0] + 1;

    return answer;
}


void swap_elements(int* arr, int index_start, int index_end) {
    
    int temp;
    for(int i = 0; i < (index_end - index_start + 1) / 2; i++) {

        temp = *(arr + index_start + i);
        *(arr + index_start + i) = *(arr + index_end - i);
        *(arr + index_end - i) = temp;
    }
}

