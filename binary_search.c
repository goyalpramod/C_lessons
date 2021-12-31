#include<stdio.h>

int binary_search(int a[], int num, int size){
int low,high,mid;
low = 0;
high = size-1;

while(low<=high){
    mid = (low+high)/2;
    if(a[mid] == num){
        return mid;
    }
    else if(num>mid){
        low = mid + 1;
    }else{
        high = mid - 1;
    }
return -1;
}
}

int main(){
    int arr[10] = {1,4,7,9,22,45,67};
    int size = 7;
    int num = 9;
    int ans;
    ans = binary_search(arr,num,size);
    printf("The index of %d is %d", num, ans);
    return 0;
}