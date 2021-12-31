#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
}circularQueue;

int isFull(circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(circularQueue *q){
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(circularQueue *q, int val){
    if(isFull(q)){
        printf("Queue is Full");
    }else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        return -1;
    }else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

void show(circularQueue *q){
    for(int i = q->f + 1;i<q->r+1;i++){
        printf("The element is %d\n", q->arr[i]);
    }
}

int main(){
    circularQueue q;
    q.size = 10;
    q.f=q.r= 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q,7);
    enqueue(&q,9);
    enqueue(&q,2);
    show(&q);
    dequeue(&q);
    printf("After dequeue\n");
    show(&q);
    return 0;
}