#include<stdio.h>

void show(int a[], int len){
    for (int i = 0; i< len; i++){
        printf("%d\n", a[i]);
    }
}

void insert(int * ptr, int num, int *size , int pos){
    ++(*size);
    for(int i = *size; i > pos; i--){
        ptr[i] = ptr[i-1];
    }
    ptr[pos] = num;
}

void delete(int arr[],int size, int pos){
    for(int i = pos; i<size; i++){
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr[10] = {3,7,9,12,34};
    int size = 5;
    int num = 69;
    int pos = 2;
    int pos_del = 3;
    printf("original array \n");
    show(arr,size);
    insert(&arr,num,&size,pos);
    printf("arr after insertion\n");
    show(arr,size);
    delete(arr,size,pos_del);
    --size;
    printf("array after deletuion is \n");
    show(arr,size);

    return 0;
}