#include<stdio.h>

void bubble_sort(char *arr){
    int temp = 0;
    int isSorted; //this is to make adaptive, awesome shit. remember it.
    for(int i = 0; i < 4; i++){
        isSorted = 1;
        for(int j = 0; j < 5 - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                isSorted = 0;
            }
        if(isSorted){
            return;
        }
        }
    }
}

void show(char *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    char a[] = {3,6,1,2,5};
    show(a);
    bubble_sort(a);
    show(a);
    return 0;
}