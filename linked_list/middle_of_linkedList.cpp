#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int data;
    struct node *link;
};

void insertNode(struct node **head_ref){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter data for the node: ";
    cin>>temp->data;
    temp->link = *head_ref;
    *head_ref = temp;
}

void printList(struct node **head_ref){
    struct node *temp = *head_ref;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

void middleOfList(struct node **head_ref){
    struct node *single = *head_ref, *twice = *head_ref;
    while(twice!=NULL && twice->link!=NULL){
        single = single->link;
        twice = twice->link->link;
    }
    cout<<"Middle of the list is "<<single->data;
}

int menu(){
    int ch;
    cout<<"\n**Menu**\n1. Add Data\n2. View Data\n3. Get the middle\n4. Exit\nEnter your choice: ";
    cin>>ch;
    return ch;
}

int main(){
    struct node *head = NULL;
    
    while(1){
        switch(menu()){
            case 1: insertNode(&head);
                break;
            case 2: printList(&head);
                break;
            case 3: middleOfList(&head);
                break;
            case 4: exit(0);
                break;
            default: cout<<"Wrong choice!\n";
                break;
        }
    }

    return 0;
}