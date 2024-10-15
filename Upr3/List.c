
// Write a program that implements a singly linked list
// The first added element points to NULL
// The last added element is pointed by some pointer, let's say <list>

#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list* next;
};

void insert(struct list**, int);
void insert_after(struct list**, int, int);
void insert_before(struct list**, int, int);
void delete_element(struct list**, int);
void print_list(const struct list*);

int main() {

    struct list* list = NULL;

    for(int k = 10; k <= 20; k++)
        insert(&list, k);
    
    printf("list points to = %p\n", list);

    insert(&list, 23);
    printf("list points to = %p\n", list);

    insert_after(&list, 23, 24);
    printf("list points to = %p\n", list);

    insert_before(&list, 23, 22);
    printf("list points to = %p\n", list);

    insert_after(&list, 10, 32);
    printf("list points to = %p\n", list);

    insert_after(&list, 9, 32);
    printf("list points to = %p\n", list);

    delete_element(&list , 10);
    printf("list points to = %p\n", list);
    
    delete_element(&list , 32);
    printf("list points to = %p\n", list);
    
    print_list(list);

    return 0;
}


// inserts element in the begining of the list
// (just like the push() function of stack)
void insert(struct list** list, int data) {

    struct list* ptr = (struct list*)malloc(sizeof(struct list));

    if(!ptr)
        return;
    
    ptr -> data = data;

    ptr -> next = (*list);
    (*list) = ptr;

    printf("%d inserted to list\n", ptr -> data);
}


void insert_after(struct list** list, int key, int data) {

    // check if list is empty
    if(!(*list)){
        insert(list, data);
        return;
    }

    struct list* temp;
    for(temp = (*list); temp -> next && temp -> data != key; temp = temp -> next);
    // after for loop the key is found, or no key is found, depending
    // on which of the two conditions terminates the loop
    // check if we have found the key

    if(temp -> data == key){

        struct list* ptr = (struct list*)malloc(sizeof(struct list));

        if(!ptr)
            return;

        ptr -> data = data;
        ptr -> next = temp -> next;
        temp -> next = ptr;
        printf("%d inserted after %d\n", ptr -> data, temp -> data);
        return;
    }

    printf("no key = %d found\n", key);
}


void insert_before(struct list** list, int key, int data) {

    //check if list is empty
    //check if key is the fist element
    if(!(*list) || (*list) -> data == key){
        insert(list, data);
        return;
    }

    struct list* temp;
    for(temp = (*list); temp -> next && temp -> data != key; temp = temp -> next);
    // after for loop the key is found, or no key is found, depending
    // on which of the two conditions terminates the loop
    // check if we have found the key


    if(temp -> data == key) {

        struct list* ptr = (struct list*)malloc(sizeof(struct list));

        if(!ptr)
            return;
        
        ptr -> data = temp -> data;
        ptr -> next = temp -> next;
        temp -> next = ptr;
        temp -> data = data;

        printf("%d inserted before %d\n", temp -> data, ptr -> data);
        return;
    }

    printf("no key = %d found\n", key);
}

void print_list(const struct list* list) {

    while(list -> next){

        printf("%d ", list -> data);
        list = list -> next;
    }

    // because last element is skipped in while loop
    printf("last element %d ", list -> data);
}

void delete_element(struct list** list, int key) {

    // check if list is empty
    if(!(*list))
        return;

    struct list* ptr = (*list);

    // delete first element
    if((*list) -> data == key) {

        (*list) = (*list) -> next;
        printf("%d deleted from list\n", ptr -> data);
        free(ptr);
        return;
    }
    for(; ptr -> next -> next && ptr -> next -> data != key; ptr = ptr -> next);
    // after for loop the key is either found or not
    // we do check if key is found
    // ptr points either to the one before last element, or to the element before the key

    if(ptr -> next -> data == key) {
        
        struct list* temp;
        temp = ptr -> next;
        ptr -> next = temp -> next;
        printf("%d deleted from list\n", temp -> data);
        free(temp);
        return;
    }

    printf("no key = %d found\n", key);
}


