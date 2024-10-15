
// Write a program that implements a queue
// Use two pointers -> head - points to the fist added element, 
// tail - points to the last added element
// the last element points to NULL

// FIFO style

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue* next;
};

void enqueue(struct queue**, struct queue**, int);
void dequeue(struct queue**);

int main() {

    struct queue* head = NULL;
    struct queue* tail = NULL;

    int i = 2;
    while(i <= 10){
        
        enqueue(&head, &tail, i);
        i +=2 ;
    }

    printf("head points to = %p\n", head);
    printf("tail points to = %p\n", tail);

    dequeue(&head);
    dequeue(&head);

    printf("head points to = %p\n", head);
    printf("tail points to = %p\n", tail);

    return 0;
}

void enqueue(struct queue** head, struct queue** tail, int data) {

    struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));

    if(!ptr)
        return;
    
    ptr -> next = NULL;
    ptr -> data = data;
    
    // check if the queue is empty
    if(!(*head))
        (*head) = ptr;
    else
        (*tail)->next = ptr;
    
    (*tail) = ptr;

    printf("%d enqueued\n", ptr -> data);
}

void dequeue(struct queue** head) {

    // check if the queue is empty
    if(!(*head))
        return;

    struct queue * temp = *head;
    (*head) = temp -> next;

    printf("%d dequeued\n", temp -> data);
    free(temp);
}

