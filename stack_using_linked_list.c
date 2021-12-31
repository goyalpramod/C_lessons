#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void linked_list_traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}


node *push(node *ptr,int val){
    if(is_full(ptr)){
        printf("FULL son");
    }else{
        node *p = (node *)malloc(sizeof(node));
        p->data = val;
        p->next = ptr;
        ptr = p;
        return ptr;
    }
}

int pop(node **ptr){
    if(is_empty(*ptr)){
        printf("empty boi");
    }else{
    node *p = (*ptr);
    int num = (*ptr)->data;
    *ptr = (*ptr)->next;
    free(p);
    return num;
    }
}

int peak(node *ptr,int i){
    node *p = ptr;
    int j = 0;
    while(p->next != NULL && j<i){
        p = p->next;
    }
    if(p->next = NULL){
       return -1;
    }
    return p->data;
}

int is_empty(node *ptr){
    if (ptr == NULL){
        return 1;
    }
    return 0;
}

int is_full(node *ptr){
    node *n;
    n = (node *)malloc(sizeof(node));
    if(n == NULL){
        return 1;
    }else{
        free(n);
        return 0;
    }
}

int stack_top(node *ptr){
    return ptr->data;
}

int stack_bottom(node *ptr){
    node *p = ptr;
    while(p->next != NULL){
        p = p->next;
    }
    return p->data;
}

int main(){
    node *top;
    top = NULL;
    top = push(top,7);
    top = push(top,9);
    int element = pop(&top);
    printf("The poped element is %d\n", element);
    top = push(top,11);
    linked_list_traversal(top);
    int peak1 = peak(top,1);
    printf("Element at 1 is %d",peak1);

    return 0;
}