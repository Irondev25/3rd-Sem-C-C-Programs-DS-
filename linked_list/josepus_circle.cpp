#include<iostream>
#include<stdio.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertNode(struct node **head_ref, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node = *head_ref;
    *head_ref = new_node;
}

int main(){

    return 0;
}