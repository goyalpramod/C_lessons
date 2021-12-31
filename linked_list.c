#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *insert_beginning(node *head,int data){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

node *insert_end(node *head,int data){
    node *p = head;
    node *ptr = (node *)malloc(sizeof(node));
    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

node *insert_in_between(node *head,int data,int index){ //my take on it 
    node *ptr = (node *)malloc(sizeof(node)); // here we can do node *ptr = head
    node *ptr1 = (node *)malloc(sizeof(node));   
    ptr->next = head;
    for(int i = 0; i < index-1; i ++){
        ptr = ptr->next;
    }
    ptr1->next=ptr->next;
    ptr1->data = data;
    ptr->next = ptr1;
    return head;
}

node *insert_after_node(node *head,node *ptr,int data){
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
    return head;
} //node value is known, insert after that

node *delete_beginning(node *head){
    node *p = head;
    head = p->next;
    free(p);
    return head;
}

node *delete_in_between(node *head,int index){
    node *p = head;
    node *d = (node *)malloc(sizeof(node));
    for(int i = 0; i<index-1;i++){
        p = p->next;
    }
    d=p->next;
    p->next = d->next;
    free(d);
    return head;
}

node *delete_last(node *head){
    node *p = head;
    node *q = p->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;
    return head;
}

node *delete_after_node(node *head,node *ptr){
    node *d = ptr->next;
    ptr->next = d->next;
    free(d);
    return head;
}

void linked_list_traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    node *head;
    node *second;
    node *third;
    node *ptr;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    head->data = 12;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 62;
    third->next = NULL;

    int data = 23;
    int index = 3;

    printf("before inserting\n");
    linked_list_traversal(head);
    
    printf("after inserting in the beginning\n");
    head = insert_beginning(head,data);
    linked_list_traversal(head);
    
    printf("after inserting in the 3rd index\n");
    head = insert_in_between(head,data,index);
    linked_list_traversal(head);
    
    printf("after inserting in the ned\n");
    head = insert_end(head,data);
    linked_list_traversal(head);
    
    printf("after inserting after second element\n");
    head = insert_after_node(head,second,76);
    linked_list_traversal(head);

    printf("after deleting first element\n");
    head = delete_beginning(head);
    linked_list_traversal(head);

    printf("after deleting 3rd element\n");
    head = delete_in_between(head,2);
    linked_list_traversal(head);

    printf("after deleting the last element\n");
    head = delete_last(head);
    linked_list_traversal(head);

    printf("after deleting after 1st element\n");
    head = delete_after_node(head,head);
    linked_list_traversal(head);
    return 0;
}