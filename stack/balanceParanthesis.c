#include<stdio.h>
#include<malloc.h>


struct stack{
    int top;
    int capacity;
    char *arr;
};


struct stack *createStack(int length){
    struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack));
    new_stack->top = -1;
    new_stack->capacity = length;
    new_stack->arr = (char *)malloc(sizeof(char)*length);
    return new_stack;
}


int isEmpty(struct stack *ss){
    if(ss->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ss){
    if (ss->top > ss->capacity-1)
        return 1;
    return 0;
}

void push(struct stack *ss, char data){
    if(!isFull(ss)){
        ss->top++;
        ss->arr[ss->top] = data;
    }
    else{
        printf("List is Full.\n");
    }
}

char pop(struct stack *ss){
    char temp;
    if(!isEmpty(ss)){
        temp = ss->arr[ss->top];
        ss->top--;
    }
    else{
        return '\0';
    }
    return temp;
}

char peek(struct stack *ss){
    return ss->arr[ss->top];
}

void display(struct stack *ss){
    int i;
    printf("\nThe Stack is: ");
    for(i=0; i<=ss->top; i++){
        printf("%d ", ss->arr[i]);
    }
}

void checkParanthesis(char *expr, int length){
    int counter = 0, i;
    struct stack *ss = createStack(length);
    for(i=0; i<length; i++)
    {
        if(*expr == '(' || *expr == '{' || *expr == '['){
            push(ss, *expr);
        }
        if(*expr == ')'){
            if(peek(ss) == '('){
                pop(ss);
                counter = 1;
            }
            else
            {
                counter = 0;
                break;
            }
        }

        if(*expr == '}'){
            if(peek(ss) == '{'){
                pop(ss);
                counter = 1;
            }
            else
            {
                counter = 0;
                break;
            }
        }

        if(*expr == ']'){
            if(peek(ss) == '['){
                pop(ss);
                counter = 1;
            }
            else
            {
                counter = 0;
                break;
            }
        }
        ++expr;
    }
    if(counter == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}


int main(){
    char expr[] = "{()}[]";
    checkParanthesis(expr, 6);
    return 0;
}