//this is valid for unsorted linked list

#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *link;
};

void insertNode(struct node **head_ref, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *head_ref;
    *head_ref = new_node;
}

void deleteNode(struct node *head, struct node *search){
    struct node *curr=head, *prev=NULL;
    while(curr!=NULL){
        if(curr == search)
            break;
        prev = curr;
        curr = curr->link;
    }
    prev->link = curr->link;
    free(curr);
}

void printNode(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        cout<<" "<<temp->data<<" ";
        temp = temp->link;
    }
}

void removeDuplicate(struct node *head){
    struct node *temp = head, *list = head;
    while(list!=NULL){
        temp = list->link;
        while(temp!=NULL){
            if(list->data == temp->data){
                deleteNode(head, temp);
            }
            temp = temp->link;
        }
        list = list->link;
    }
    printNode(head);
}

int main(){
    struct node *head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 11);
    insertNode(&head, 12);
    insertNode(&head, 11);
    insertNode(&head, 11);
    insertNode(&head, 12);
    insertNode(&head, 10);
    printNode(head);
    cout<<"\nRemoving Duplicates....\n";
    removeDuplicate(head);
    cout<<"\nRemoved Duplicates\n";
    return 0;
}