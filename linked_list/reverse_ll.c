#include<stdio.h>
#include<stdlib.h>


typedef struct NODE{
    int data;
    struct NODE* next;
}node;

void createLinkedList(node **head_ref){
    node *temp;
    int x;
    printf("Enter Data to insert(0 to exit):\n");
    scanf("%d", &x); 
    while(x!=0){
        temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        if(*head_ref==NULL)
            *head_ref = temp;
        else{
            temp->next = *head_ref;
            *head_ref = temp;
        }
        printf("Enter Data to insert(0 to exit):\n");
        scanf("%d", &x);
    }
}


void reverseList(node **head_ref)
{
    node *current = *head_ref, *prev = NULL, *follow = NULL;
    if (*head_ref == NULL)
        printf("List is empty.\n");
    else
    {
        while (current != NULL)
        {
            follow = current->next;
            current->next = prev;
            prev = current;
            current = follow;
        }
        *head_ref = prev;
    }
}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    node *start=NULL;
    createLinkedList(&start);
    display(start);
    reverseList(&start);
    display(start);
    return 0;
}