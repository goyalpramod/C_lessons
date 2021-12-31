#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}node;

node *createNode(int data){
    node *n;
    n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(node *root){
    if (root != NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){
    node *p;
    p = (node*)malloc(sizeof(node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    node *p1;
    p1 = (node*)malloc(sizeof(node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    node *p2;
    p2 = (node*)malloc(sizeof(node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}