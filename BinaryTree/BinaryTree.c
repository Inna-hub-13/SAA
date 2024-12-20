// Some functions for binary tree

#include <stdio.h>
#include <stdlib.h>

struct node{

    char value;
    struct node* left;
    struct node* right;
};

struct stack{

    struct node* node;
    struct stack* prev;
};

void create_tree(struct node**, char*);
void preorder(const struct node*);
void preorder_iteration(struct node*);
void inorder(const struct node*);
void postorder(const struct node*);
int power(const struct node*);
int max_el(int, int);
int depth(const struct node*);

int push(struct stack**, struct node*);
int pop(struct stack**, struct node**);

int main() {

    char x;
    struct node* root = NULL;

    create_tree(&root, &x);

    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Preorder_iteration: ");
    preorder_iteration(root);
    printf("\n");

    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}

void create_tree(struct node** root, char* x) {

    struct node* left, *right;
    char left_value, right_value;

    if(!(*root)){

        printf("Enter root: ");
        scanf(" %c", x);
        *root = (struct node*)malloc(sizeof(struct node));
        if(!(*root))
            return;
        (*root) -> value = *x;
    }

    printf("Enter left child of %c: ", *x);
    scanf(" %c", &left_value);

    printf("Enter right child of %c: ", *x);
    scanf(" %c", &right_value);

    // create left child if <left_value> is different from '0'
    if(left_value != '0'){

        left = (struct node*)malloc(sizeof(struct node));
        if(!left)
            return;
        left -> value = left_value;
        (*root) -> left = left;
            create_tree(&left, &left_value);
            
    }
    else
        (*root) -> left = NULL;

    // create left child if <left_value> is different from '0'
    if(right_value != '0'){

        right = (struct node*)malloc(sizeof(struct node));
        if(!right)
            return;
        right -> value = right_value;
        (*root) -> right = right;
            create_tree(&right, &right_value);
    }
    else
        (*root) -> right = NULL;
}

void preorder(const struct node* root) {

    if(root != NULL){
        printf("%c ", root -> value);
        preorder(root->left);
        preorder(root->right);
    }

}

void inorder(const struct node* root){

    if(root != NULL){
        inorder(root->left);
        printf("%c ", root->value);
        inorder(root->right);
    }
}

void postorder(const struct node*root) {

    if(root != NULL){

        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->value);
    }
}

// counts number of nodes of the binary tree
int power(const struct node* root) {

    if(root == NULL)
        return 0;
    
    return 1 + power(root->left) + power(root->right);
}

int max_el(int a, int b) {

    return a > b ? a : b;
}

int depth(const struct node* root) {

    if(root == NULL)
        return 0;
    
    return 1 + max_el(depth(root->left), depth(root->right));
}

int push(struct stack** top, struct node* node) {

    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if(!temp)
        return -1;
    
    temp->prev = *top;
    *top = temp;
    temp->node = node;
    return 0;
}

int pop(struct stack** top, struct node** node) {

    if(!(*top))
        return -1;
    
    struct stack* temp = *top;
    *top = (*top)->prev;
    *node = temp->node;
    free(temp);
    return 0;
}

void preorder_iteration(struct node* root) {

    struct stack* top = NULL;
    struct node* temp_node = NULL;

    if(root)
        push(&top, root);
    else 
        return;

    while(top){

        pop(&top, &temp_node);
        printf("%c ", temp_node -> value);

        if(temp_node->right)
            push(&top, temp_node->right);
        
        if(temp_node->left)
            push(&top, temp_node->left);
    }
}
