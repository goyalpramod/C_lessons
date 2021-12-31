#include<stdio.h>

int main(){
    int a,b,c;
    float percentage;
    printf("Enter the marks of the student \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);  
    percentage = ((a + b + c) /300) * 100;
    if (percentage > 33){
        printf("pass\n");
    }else{
        printf("Fail\n");
    }
    printf("%f", percentage);
    printf("%d", a);
    return 0;
}
