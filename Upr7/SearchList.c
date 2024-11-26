#include <stdio.h>
#include <stdlib.h>

struct list{

    int value;
    struct list* next;
};

int insert(struct list**, int);
int delete_first(struct list**, int*);
struct list* search_node(struct list*, int);

int main() {

    struct list* head = NULL;
    struct list* temp;
    int val;

    insert(&head, 7);
    insert(&head, -2);
    insert(&head, 5);
    insert(&head, 12);
    insert(&head, 11);
    
    for(temp = head; temp; temp = temp -> next)
        printf("%d ", temp -> value);
    printf("\n");
    
    temp = search_node(head, 13);
    if(temp)
        printf("temp -> value = %d\n", temp -> value);

    temp = search_node(head, 7);
    if(temp)
        printf("temp -> value = %d\n", temp -> value);

    return 0;
}

int insert(struct list** head, int value) {

    struct list* temp = (struct list*)malloc(sizeof(struct list));
    if(!temp)
        return -1;
    
    temp -> next = *head;
    *head = temp;
    temp -> value = value;
    return 0;
}

int delete_first(struct list** head, int* val) {

    // empty list
    if(!*(head))
        return -1;

    struct list* temp = *head;
    *val = temp -> value;
    *head = temp -> next;
    free(temp);
    return 0;
}

struct list* search_node(struct list* head, int key) {

    while(head && head -> value != key)
        head = head -> next;
    
    if(head)
        return head;
    
    return NULL;
}
