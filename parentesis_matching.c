#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push to the stack\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = "(";
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesis_matching(char *exp){
    stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size*sizeof(char));
    for(int i =0;exp[i] != "\0"; i++){
        if (exp[i] == ")"){
            push(s);
        }else if(exp[i] == "("){
            if(isEmpty(s)){
                return 0;
            }
            pop(s);
        }
    }
}

int main(){
    char * exp = "*(9()7)";
    if(parenthesis_matching(exp)){
        printf("shit is right");
    }else{
        printf("shit not right");
    }
    
    return 0;
}