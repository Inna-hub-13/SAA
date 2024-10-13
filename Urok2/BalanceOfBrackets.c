
// Write a program that checks 
// if brackets are placed correctly in a string
// with the help of stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 80

// Implementation of stack
struct bracket {

    char symbol;
    struct bracket * prev;
};

void push(struct bracket **, char);
bool is_empty(const struct bracket*);
void pop(struct bracket**);
void print_bracket_stack(const struct bracket*);
void empty_stack(struct bracket**);

char mirror(char);
bool is_balanced(struct bracket**, char*);


int main() {

    struct bracket* top = NULL;
    char string_to_check[N];

    printf("\nEnter a string: ");
    // Let's use scanset characters to read whitespaces also
    scanf("%[^\n]s", string_to_check);
    printf("%s\n", string_to_check);

    printf("is_balanced = %d\n", is_balanced(&top, string_to_check));
    printf("is_balanced {)} = %d\n", is_balanced(&top, "{)}"));

    return 0;
}

void push(struct bracket ** top, char data) {

    // allocate memory for one element
    struct bracket* el = (struct bracket*)malloc(sizeof(struct bracket));

    if(!el)
        return;
    
    el -> symbol = data;
    el -> prev = *top;
    *top = el;
}

bool is_empty(const struct bracket* top) {

    return top == NULL;
}

void pop(struct bracket** top) {

    if(is_empty(*top))
        return;

    struct bracket* temp = *top;
    *top = (*top) -> prev;
    printf("%c popped out of stack\n", temp -> symbol);
    free(temp);
}

void print_bracket_stack(const struct bracket* top) {

    printf("\n");

    if(is_empty(top))
        return;

    for(; top -> prev != NULL; top = top -> prev)
        printf("%c\n", top -> symbol);

    // because last element is skipped in for
    printf("%c\n", top -> symbol);
    printf("\n");
}

void empty_stack(struct bracket** top) {

    while(!is_empty)
        pop(top);
}


char mirror(char data) {

    switch(data){
        case ')' : return '('; 
        case ']' : return '['; 
        case '}' : return '{';
        return '0';
    }
}


bool is_balanced(struct bracket** top, char* string) {

    // empty stack, so no previous elements are left
    empty_stack(top);

    int index = 0;

    while(*(string + index) != '\0'){

        // if an openning bracket is found, push it to stack
        if(*(string + index) == '(' || *(string + index) == '[' 
                || *(string + index) == '{')

            push(top, *(string + index));

        else if(*(string + index) == ')' || *(string + index) == ']' 
                || *(string + index) == '}') {

                if((*top) && (*top) -> symbol == mirror(*(string + index)))
                    pop(top);

                else
                    return false;
        }

        index++;
    }

    // no elements left -> every closing bracket must have had a matching
    // equivalent
    if((*top) == NULL)
        return true;
    else
        return false;
}
