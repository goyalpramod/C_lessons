#include<stdio.h>

void show(int *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partion(int a[],int low,int high){
    int pivot = a[low];
    int i = low+1;
    int j = high;
    do{
        while (a[i]<=pivot)
        {
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if(i<j){
        swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&a[low],&a[j]);
    return j;
}

void quick_sort(int a[], int low,int high){
    int partion_index;
    if(low<high){
    partion_index = partion(a,low,high);
    quick_sort(a,low,partion_index-1);
    quick_sort(a,partion_index+1,high);
    }
}

int main(){
    int a[] = {7,1,4,9,5};
    int n = 5;
    show(a);
    quick_sort(a,0,4);
    printf("apple\n");
    show(a);
    return 0;
}
