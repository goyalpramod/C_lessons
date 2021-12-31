#include<stdio.h>

void insertion_sort(char *a, int n){
    int key,j;
    for(int i = 1; i<n; i++){
        key = a[i];
        j = i - 1;
        while(j>= 0 && key < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void show(char *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    char a[] = {7,1,4,9,5};
    int n = 5;
    show(a);
    insertion_sort(a,n);
    show(a);
    return 0;
}