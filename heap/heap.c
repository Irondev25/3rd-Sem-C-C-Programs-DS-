#include<stdio.h>
#include<stdlib.h>

int heap[100001]={0};
int last=0;

void show();

int Parent(int i){
    return (i/2);
}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void bubble_up(int i){
    int p = Parent(i),temp;
    if(i>0 && i<=last && heap[i]>heap[p]){
        temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        if(p!=1)
            bubble_up(p);
    }
    else{
        return;
    }
}


void insert(int data){
    if(last==0){
        last++;
        heap[1] = data;
        return;
    }
    if(last!=(100000)){
        ++last;
        heap[last] = data;
        bubble_up(last);
    }
}


void show(){
    int i=0;
    for(i=1; i<=last; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main(){
    int i;
    for(i=1; i<=20; i++)
        insert(i);
    show();
    return 0;
}