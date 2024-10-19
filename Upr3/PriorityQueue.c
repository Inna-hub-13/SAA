
// Write an implementation of priority queue

// Priority queue -> every element is inserted in the queue, according
// to it's rank. 0 is the highest rank. Each element is dequeued only
// from the begining of the queue.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct queue{

    int rank;
    char task[N];
    struct queue* next;
};

void insert(struct queue**, char*, int);
void dequeue(struct queue**, int);
void dequeue_n(struct queue**, int);
void print_queue(const struct queue*);
struct queue* find_position(struct queue **, int);

int main() {

    struct queue* head = NULL;
    int rank;

    insert(&head, "wash the dishes", 1);
    insert(&head, "do homework", 0);
    insert(&head, "walk the dog", 4);
    insert(&head, "cook dinner", 2);
    insert(&head, "water the plants", 6);
    insert(&head, "play scrabble", 5);
    printf("head = %p\n", head);

    print_queue(head);

    dequeue(&head, 1);
    printf("head = %p\n", head);
    print_queue(head);

    dequeue_n(&head, 2);
    printf("head = %p\n", head);
    print_queue(head);

    return 0;
}

struct queue* find_position(struct queue ** head, int rank) {

    struct queue* first = *head;
    struct queue* second = NULL;

    while(first && first -> rank < rank) {

        second = first;
        first = first -> next;
    } 

    return second;
}

void insert(struct queue** head, char* task, int rank) {

    struct queue* pos = find_position(head, rank);
    struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));

    if(!ptr)
        return;
    
    ptr -> rank = rank;
    strcpy_s(ptr -> task, N, task);

    // the queue is empty
    if(!pos) {
        ptr -> next = *head;
        *head = ptr;
    }
    else {

        ptr -> next = pos -> next;
        pos -> next = ptr;
    }

    printf("element with rank = %d inserted in queue\n", ptr -> rank);
}

// dequeues all elements with rank <= rank1
void dequeue(struct queue** head, int rank1) {

    if(!(*head))
        return;
    
    struct queue* temp;

    while((*head) -> rank <= rank1){

        temp = *head;
        *head = (*head) -> next;
        printf("element with rank %d dequeued\n", temp -> rank);
        free(temp);
    }
}

// dequeues given number of elements
void dequeue_n(struct queue** head, int n) {

    struct queue* temp;
    while(n) {

        temp = *head;
        *head = (*head) -> next;
        printf("element with rank %d dequeued\n", temp -> rank);
        n--;
    }
}

void print_queue(const struct queue* head) {

    printf("\n");
    while(head) {
        printf("element with rank %d: %s\n", head -> rank, head -> task);
        head = head -> next;
    }
    printf("\n");
}
