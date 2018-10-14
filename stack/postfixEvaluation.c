#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>


typedef struct Stack{
    int top;
    int capacity;
    double *arr;
}stack;

stack initializeStack(){
    stack s;
    s.top = -1;
    s.capacity = 50;
    s.arr = (double*)malloc(sizeof(double)*s.capacity);
    return s;
}

void push(stack *s, double data){
    if(s->top==s->capacity-1)
        return;
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

double pop(stack *s){
    double temp; 
    if (s->top == -1) 
        return 0;
    else
        temp = s->arr[s->top--];
    return temp;
}

bool isOprand(char s){
    if(s>='1'&&s<='9')
        return true;
    return false;
}

double convert(char data){
    return (double)data-48;
}

double EvalUtil(double a, double b, char operator){
    if(operator == '+')
        return b+a;
    else if(operator == '-')
        return b-a;
    else if(operator == '*')
        return b*a;
    else if(operator == '/')
        return b/a;
    else 
        return pow(b,a);
}

void Evaluation(char *exp){
    stack s = initializeStack();
    double a,b;
    int i;
    for(i=0; i<strlen(exp); i++){
        if(isOprand(exp[i])){
            push(&s, convert(exp[i]));
        }
        else{
            a=pop(&s); b=pop(&s);
            if(a==0||b==0){
                printf("Invalid Expression!!");
                exit(0);
            }
            push(&s, EvalUtil(a,b,exp[i]));
        }
    }
    printf("\n\nValue: %f", pop(&s));
}


int main(int argc, char const *argv[])
{
    char c[20];
    printf("Enter postfix Expression: ");
    scanf("%s", c);
    Evaluation(c);
    return 0;
}