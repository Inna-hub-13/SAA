#include <stdio.h>
#include <stdlib.h>

typedef struct list list;

struct list{

    int x;
    int y;
    list * next;
};

int addAtBeg(list**, int, int);
void traverse(const list*);
void freeList(list**);

int main() {

    list* ptrBeg = NULL;

    printf("ptrBeg = %p\n", ptrBeg);
    addAtBeg(&ptrBeg, 1, 2);
    addAtBeg(&ptrBeg, 3, 4);
    addAtBeg(&ptrBeg, 5, 6);
    printf("ptrBeg = %p\n", ptrBeg);

    traverse(ptrBeg);
    printf("ptrBeg = %p\n", ptrBeg);

    freeList(&ptrBeg);
    printf("After free() ptrBeg = %p\n", ptrBeg);

}

int addAtBeg(list** ptrBeg, int x, int y){

    list* temp = (list*)malloc(sizeof(list));
    if(!temp)
        return -1;

        temp->x = x;
        temp->y= y;
    
    temp->next = (*ptrBeg);

    *ptrBeg = temp;
    return 0;
}

void traverse(const list* ptrBeg){

    for(;ptrBeg != NULL; ptrBeg = ptrBeg->next)
        printf("%p x = %d, y = %d\n", ptrBeg, ptrBeg->x, ptrBeg->y);
}

void freeList(list** ptrBeg) {

    list* temp = *ptrBeg;
    while(temp){

        *ptrBeg = temp->next;
        free(temp);
        temp = *ptrBeg;
    }
}
