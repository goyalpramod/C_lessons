#include<stdio.h>

void show(int *arr){
    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int *a,int mid, int low, int high){
    int i,j,k,b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i<=mid && j<=high)
    {
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;
        }else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        b[k] = a[i];
        i++;k++;
    }
    while(j<=high){
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
    
}

void merge_sort(int a[], int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a, mid + 1,high);
        merge(a,mid,low,high);
    }
}

int main(){
    int a[] = {7,1,4,9,5};
    int n = 5;
    show(a);
    merge_sort(a,0,4);
    show(a);
    return 0;
}
