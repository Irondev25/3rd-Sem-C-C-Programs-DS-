#include<stdio.h>
#include<stdlib.h>

int arr[10];
int front = -1;
int rear = -1;
int size = 10;

void insert(int data){
    if(rear == (size-1)){
        printf("Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear++;
    arr[rear] = data;
}

int del(){
    int temp;
    if(front>rear || front == -1){
        printf("Underflow\n");
        return 0;
    }
    temp = arr[front];
    front++; 
    return temp;
}

void show(){
    int i;
    for(i=front; i<=rear; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int data;
    char ch;
    printf("Enter Data: ");
    scanf("%d", &data);
    while (data != 0)
    {
        insert(data);
        show();
        printf("Enter Data: ");
        scanf("%d", &data);
    }
    ch = 'y';
    while (ch == 'y')
    {
        printf("%d", del());
        show();
        printf("Want to delete again: ");
        scanf("%c", &ch);
    }
    show();
    return 0;
}