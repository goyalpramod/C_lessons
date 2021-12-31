#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int size;
    int f;
    int r;
    int *arr;
}queue;

void enqueue(queue *q, int val){
    if(q->r == q->size - 1){
        printf("Queue is Full");
    }else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(queue *q){
    int a = -1;
    if(q->r == q->f){
        return -1;
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    queue q;
    q.size = 10;
    q.f=q.r= -1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q,7);
    enqueue(&q,3);
    printf("dequeueing element %d", dequeue(&q));
    for(int i = 0; i < 2; i++){
        printf("%d\n",q.arr[i]);
    }
    return 0;
}