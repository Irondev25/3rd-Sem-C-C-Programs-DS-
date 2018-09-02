#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *link;
};

void insertNode(struct node **head_ref ,int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *head_ref;
    *head_ref = new_node;
}

void printNode(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

void intersectionOfList(struct node *list1, struct node *list2){
    struct node *commonList, *temp1, *temp2;
    temp1 = list1;
    temp2 = list2;
    while(temp1!=NULL){
        temp2 = list2;
        while(temp2!=NULL){
            if(temp1->data == temp2->data){
                insertNode(&commonList, temp1->data);
                temp2 = temp2->link;
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    printNode(commonList);
}

int main(){
    struct node *a = NULL;
    struct node *b = NULL;

    insertNode(&a, 6);
    insertNode(&a, 5);
    insertNode(&a, 4);
    insertNode(&a, 3);
    insertNode(&a, 2);
    insertNode(&a, 1);

    insertNode(&b, 8);
    insertNode(&b, 6);
    insertNode(&b, 4);
    insertNode(&b, 2);
    cout<<"Data inserted";
    intersectionOfList(a, b);
    return 0;
}