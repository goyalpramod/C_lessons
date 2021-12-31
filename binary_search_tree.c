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

int isBST(node *root){
    static node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && prev->data >= root->data){
            return 1;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

node *search(node *root,int val){
    if(root == NULL){
        return NULL;
    }if(root->data = val){
        return root;
    }else if(root->data > val){
        search(root->left,val);
    }else{
        search(root->right,val);
    }
}

void insert(node *root, int val){
    node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == val){
            return;
        }else if(val < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    node *new = createNode(val);
    if(val<prev->data){
        prev->left = new;
    }else{
        prev->right = new;
    }
}

node *inOrderPredecessor(node *root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *delete(node *root,int val){
    node *iPre;
    // deletion
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL && root->left == NULL){
        free(root);
        return NULL;
    }
    // Search for node to be deleted
    if(val<root->data){
        root->left = delete(root->left,val);
    }else if(val > root->data){
        root->right = delete(root->right,val);
    }
    // deletion strat when node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete(root->left,iPre->data);
    }
    return root;
}

int main(){
    node *p;
    p = (node*)malloc(sizeof(node));
    p->data = 5;
    p->left = NULL;
    p->right = NULL;

    node *p1;
    p1 = (node*)malloc(sizeof(node));
    p1->data = 3;
    p1->left = NULL;
    p1->right = NULL;

    node *p2;
    p2 = (node*)malloc(sizeof(node));
    p2->data = 8;
    p2->left = NULL;
    p2->right = NULL;

    node *p3 = createNode(4);
    node *p4 = createNode(2);
    node *p5 = createNode(11);
    node *p6 = createNode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p4;
    p1->right = p3;
    p2->left = p6;
    p2->right = p5;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    printf("%d", isBST(p));
    printf("\n");
    node *ptr = search(p,8);
    printf("%d",ptr->data);
    printf("\n");
    insert(p,23);
    inOrder(p);
    delete(p,4);
    printf("\n");
    inOrder(p);
    return 0;
}