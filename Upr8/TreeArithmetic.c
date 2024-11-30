
// Create a tree for which every leaf is a digit (1 to 9), the other nodes
// are operators (+, -, *). Calculate the expresion,fromed by the tree.

#include <stdio.h>
#include <stdlib.h>

struct node{

    char value;
    struct node* left;
    struct node* right;
};

void create_tree(struct node**, char);
void inorder(const struct node*);
int calculate(const struct node*);

int main() {

    struct node* root = NULL;

    printf("0 means no child\n");
    create_tree(&root, '+');
    inorder(root);
    printf(" = %d\n", calculate(root));

    return 0;
}

void create_tree(struct node** root, char root_value) {

    char x = root_value, l, r;
    struct node *left, *right;

    // root is empty, create it
    if(!(*root)){

        *root = (struct node*)malloc(sizeof(struct node));
        if(!(*root))
            return;

        (*root) -> value = x;
    }

    printf("Enter left child of \'%c\' : ", x);
    scanf(" %c", &l);

    printf("Enter right child of \'%c\' : ", x);
    scanf(" %c", &r);

    if(l != '0') {

        left = (struct node*)malloc(sizeof(struct node));
        if(!left)
            return;
        
        left->value = l;
        (*root)->left = left;
        create_tree(&left, l);
    }
    else
        (*root)->left = NULL;

    if(r != '0') {

        right = (struct node*)malloc(sizeof(struct node));
        if(!right)
            return;
        
        right->value = r;
        (*root)->right = right;
        create_tree(&right, r);
    }
    else
        (*root)->right = NULL;
}

void inorder(const struct node* root) {

    if(root){

        inorder(root->left);
        printf("%c ", root->value);
        inorder(root->right);
    }
}

int calculate(const struct node* root) {

    if(root){

        if(root->value >= '1' && root->value <= '9')
            return root->value - '0';
    
        switch(root->value){

            case '+': return calculate(root->left) + calculate(root->right);
            break;
            case '-': return calculate(root->left) - calculate(root->right);
            break;
            case '*': return calculate(root->left) * calculate(root->right);
            break;
        }
    }
}