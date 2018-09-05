#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

struct ArrayStack{
    int top;
    int capacity;
    char *arr;
};

struct ArrayStack* createStack(){
    struct ArrayStack *new_stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    new_stack->top = -1;
    new_stack->capacity = 30;
    new_stack->arr = (char *)malloc(sizeof(char) * new_stack->capacity);
    return new_stack;
}


bool isEmpty(struct ArrayStack *s){
    if(s->top == -1)
        return true;
    return false;
}

bool isFull(struct ArrayStack *s){
    if(s->top == 29)
        return true;
    return false;
}


void push(struct ArrayStack **stack ,char data){
    if(!isFull(*stack)){
        (*stack)->top++;
        (*stack)->arr[(*stack)->top] = data;
    }
}


char pop(struct ArrayStack **stack){
    char temp;
    if(!isEmpty(*stack)){
        temp = (*stack)->arr[(*stack)->top];
        (*stack)->top--;
        return temp;
    }
    return '\0';
}


char peek(struct ArrayStack *s){
    if(!isEmpty(s))
        return s->arr[s->top];
    return '\0';
}


int priority(char data){
    if(data == '+' || data == '-')
        return 1;
    else if(data == '*' || data == '/')
        return 2;
    else if(data == '^')
        return 3;
    else
        return -1;        //imp statement
}


int main(){
    char expression[30], *expr, x;
    struct ArrayStack *stack = createStack();
    printf("Enter an Expression: ");
    scanf("%s", expression);
    expr = expression;
    printf("Given Expression: %s\n", expr);
    printf("Postfix Expression: ");
    while(*expr != '\0'){
        //if character is operator
        if(isalnum(*expr))
            printf("%c", *expr);
        else if(*expr == '(')
            push(&stack, *expr);
        else if(*expr == ')'){
            while(!isEmpty(stack) && (x=pop(&stack)) != '('){
                printf("%c", x);
            }
        }
        else{
            while(!isEmpty(stack) && priority(peek(stack)) >= priority(*expr))
                printf("%c", pop(&stack));
            push(&stack, *expr);
        }
        expr++;
    }
    while(!isEmpty(stack)){
        printf("%c", pop(&stack));
    }
    printf("\n");
    return 0;
}