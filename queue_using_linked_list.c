#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *f = NULL;
node *r = NULL;

void enqueue(int val){
    node *ptr = (node *)malloc(sizeof(node));
    if(f == NULL){
        ptr->data = val;
        ptr->next = NULL;
        f = r = ptr;
    }else{
        ptr->data = val;
        ptr->next = NULL;
        r->next = ptr;
        r = ptr;
    }
}

int dequeue(){
    node *ptr = (node *)malloc(sizeof(node));
    int val = 0;
    if(f == NULL){
        return -1;
    }else{
        ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

void linked_list_traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    enqueue(5);
    enqueue(7);
    enqueue(2);
    linked_list_traversal(f);
    printf("After dequeue \n");
    dequeue();
    linked_list_traversal(f);
    return 0;
}