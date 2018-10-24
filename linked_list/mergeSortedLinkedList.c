#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node** head_ref, int data){
    node* temp=*head_ref, *t=(node*)malloc(sizeof(node));
    t->data = data;
    t->next = NULL;
    if(*head_ref==NULL)
        *head_ref = t;
    else{
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = t;
    }
}

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* merge(node* head1, node* head2){
    node* temp = NULL;
    if(head1==NULL && head2==NULL)
        return NULL;
    if(head1==NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data<=head2->data)
        head1->next = merge(head1->next, head2);
    else{
        temp = head2;
        head2 = head2->next;
        temp->next = head1;
        head1 = temp;
        head1->next = merge(head1->next, head2);
    }
    return head1;
}

int main(){
    node* head1=NULL, *head2=NULL;
    push(&head1, 2);
    push(&head1, 5);
    push(&head1, 9);
    push(&head1, 13);
    push(&head2, 4);
    push(&head2, 14);
    print(head1);
    print(head2);
    printf("Now merging\n");
    head1 = merge(head1, head2);
    print(head1);
    return 0;
}