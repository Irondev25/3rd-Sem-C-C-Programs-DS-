#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int data;
    struct node *link;
};

void insertNode(struct node **start_ref, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *start_ref;
    *start_ref = new_node;
}

struct stack{
    int top;
    int capacity;
    int *arr;

    stack(): top(-1), capacity(10){
        arr = (int *)malloc(capacity * sizeof(int));
    }

    void push(int data){
        top++;
        arr[top] = data;
    }

    int pop(){
        int temp = arr[top];
        top--;
        return temp;
    }
};

void palindrome(struct node *head){
    struct stack s;
    struct node *temp = head;
    while(temp!=NULL){
        s.push(temp->data);
        temp = temp->link;
    }

    temp = head;
    while(temp!=NULL){
        if (temp->data != s.pop())
            break;
        temp = temp->link;
    }
    
    if(temp == NULL)
        cout<<"List is a palindrome";
    else
        cout<<"List is not palindrome";
}

int main(){
    struct node *start = NULL;
    insertNode(&start, 1);
    insertNode(&start, 2);
    insertNode(&start, 3);
    insertNode(&start, 4);
    insertNode(&start, 2);
    insertNode(&start, 1);
    palindrome(start);
    return 0;
}