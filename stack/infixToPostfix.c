#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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


int isEmpty(struct ArrayStack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int isFull(struct ArrayStack *s){
    if(s->top == 30)
        return 1;
    return 0;
}


void push(struct ArrayStack *stack ,char data){
    if(!isFull(stack)){
        stack->top++;
        stack->arr[stack->top] = data;
    }
}


char pop(struct ArrayStack *stack){
    char temp;
    if(!isEmpty(stack)){
        temp = stack->arr[stack->top];
        stack->top--;
        return temp;
    }
    return '\0';
}


char peek(struct ArrayStack *s){
    if(!isEmpty(s))
        return s->arr[s->top];
}

int isOprator(char data){
    if(data == '+' || data == '-' || data=='*' || data=='/' || data == '^')
        return 1;
    return 0;
}


int oprandPrecedence(char data){
    if(data == '+' || data == '-')
        return 1;
    if(data == '*' || data == '/')
        return 2;
    if(data == '^')
        return 3;
}


int main(){
    char expression[30], *expr;
    struct ArrayStack *stack = createStack();
    printf("Enter an Expression: ");
    scanf("%s", expression);
    expr = expression;
    printf("Given Expression: %s\n", expr);
    printf("Postfix Expression: ");
    while(*expr){
        if(isalpha(*expr)){
            printf("%c", *expr);
        }
        else if(*expr == '(')
            push(stack, *expr);
        else if(*expr == ')'){
            while(!isEmpty(stack) && peek(stack) != '(')
                printf("%c", pop(stack));
            pop(stack);
        }
        else if(isOprator(*expr)){
            while(oprandPrecedence(peek(stack)) > oprandPrecedence(*expr)){
                printf("%c", pop(stack));
            }
            push(stack ,*expr);
        }
        expr++;
    }
    while(!isEmpty(stack)){
        printf("%c", pop(stack));
    }
    printf("\n");
    return 0;
}