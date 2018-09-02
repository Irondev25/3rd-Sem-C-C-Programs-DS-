#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

//function for menu
int menu();

//function to createNode
void insertNewNode(struct node **);

// function to print node
void print(struct node **);

//function for swapping node
void swapNode(struct node **);

int main(){
    struct node *start = NULL;
    while (1){
        switch (menu())
        {
        case 1:
            insertNewNode(&start);
            break;
        case 2:
            print(&start);
            break;
        case 3:
            swapNode(&start);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "You've entered wrong choice!";
            break;
        }
    }
    return 0;
}

int menu()
{
    int ch;
    cout << "\n\nMenu";
    cout << "\n1. Enter new data.";
    cout << "\n2. Print list";
    cout << "\n3. swap 2 nodes.";
    cout << "\n4. exit";
    cout << "\nEnter your choice.";
    cin >> ch;
    return ch;
}

void insertNewNode(struct node **head_ref)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    cout << "Enter new Data: ";
    cin >> new_node->data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print(struct node **head_ref){
    struct node *temp = *head_ref;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void swapNode(struct node **head_ref){
    struct node *currX = *head_ref, *prevX = NULL, *currY = *head_ref, *prevY = NULL, *temp;
    int x,y;
    cout<<"\nEnter data to swap: ";
    cout<<"\n1st data: ";
    cin>>x;
    cout<<"\n2nd data: ";
    cin>>y;

    //if both of them are same
    if(x == y) return;

    //searching for x
    while(currX && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    //searching for y
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL)
        return;
    
    //if x is head or not
    if(prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;
        
    //if y is head or not
    if(prevY == NULL)
        *head_ref = currX;
    else
        prevY->next = currX;  

    temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}