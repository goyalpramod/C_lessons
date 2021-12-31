#include<stdio.h>

void selection_sort(int *a, int n){
    int temp,min;
    for(int i = 0;i<n - 1;i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void show(int *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {4,1,9,2,5};
    int n = 5;
    show(a);
    selection_sort(a,n);
    show(a);
    return 0;
}