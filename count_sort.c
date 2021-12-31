#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void show(int *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void count_sort(int a[], int n){
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i] > max){
            max = a[i];
        }
    }
    int *arr=(int *)malloc((max+1)*sizeof(int));
    for (int i = 0; i <max+1; i++)
    {
        arr[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[a[i]] = arr[a[i]] + 1;
    }
    int i = 0;
    int j = 0;
    while(i<=max){
        if(arr[i] != 0){
            a[j] = i;
            arr[i] = arr[i] - 1;
            j++;
        }else{
            i = i+1;
        }
    }
}

int main(){
    int a[] = {7,1,4,9,5};
    int n = 5;
    show(a);
    count_sort(a,n);
    show(a);
    return 0;
}