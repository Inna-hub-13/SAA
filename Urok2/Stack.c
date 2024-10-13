
// Write an implementation of stack

// 1) there must be a pointer, that points to the last added element -> top
// 2) fist element points to NULL
// 3) follow LIFO style

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{

    int data;
    struct stack* prev;
};

void push(struct stack**, int);
bool is_empty(const struct stack*);
int pop(struct stack**);
void print_stack(const struct stack*);

int main() {

    struct stack* top = NULL;

    printf("Top points to: %p\n", top);
    for(int i = 10; i < 25; i+=2)
        push(&top, i);
    
    printf("\nStack: \n");
    print_stack(top);

    int v1 = pop(&top);
    int v2 = pop(&top);

    printf("\nStack: \n");
    print_stack(top);
    return 0;
}

// working with the actual top
void push(struct stack** top_address, int data) {

    // first, let's allocate memory for the element
    struct stack* el = (struct stack *)malloc(sizeof(struct stack));
    if(!el)
        return;

    el -> data = data;
    el -> prev = (*top_address);
    *top_address = el;

    printf("%d pushed to stack\n", el -> data);
}

bool is_empty(const struct stack* top) {

    return top == NULL;
}

// working with actual top
int pop(struct stack** top_address) {

    if(is_empty(*top_address))
        return 0;

    struct stack* temp = *top_address;
    *top_address = temp -> prev;
    printf("%d popped out of the stack\n", temp -> data);

    free(temp);
}

void print_stack(const struct stack* top) {
    
    if(is_empty(top))
        return;
    for(; top -> prev != NULL; top = top -> prev)
        printf("%d\n", top -> data);
    
    printf("%d\n", top -> data);
}

