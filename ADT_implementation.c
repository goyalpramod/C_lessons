#include <stdio.h>
#include <stdlib.h>

struct my_array{
  int total_size;
  int used_size;
  int *ptr;
};

void creat_array(struct my_array * a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));
}

void show(struct my_array *a){
    for(int i = 0; i < a->used_size ; i++){
        printf("%d\n", (a->ptr)[i]);
    }
}

void set_array(struct my_array *a){
    int n;
    for(int i = 0; i < a->used_size ; i++){
        printf("Enter the value \n");
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct my_array marks;
    creat_array(&marks, 10 , 2);
    set_array(&marks);
    show(&marks);
    return 0;
}
