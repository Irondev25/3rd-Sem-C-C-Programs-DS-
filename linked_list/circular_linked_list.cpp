#include<iostream>
#include<malloc.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void createNInsertNode(struct node **head_ref)
{
    struct node *new_node, *t;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node:\n");
    scanf("%d", &new_node->data);
    new_node->next=NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        new_node->next = *head_ref;
    }
    else
    {
        t = *head_ref;
        while(t->next != *head_ref)
        {
            t = t->next;
        }
        t->next = new_node;
        new_node->next = *head_ref;
    }
}

void deleteNode(struct node **head_ref)
{
    struct node *temp, *del, *prev;
    temp = *head_ref;
    if(*head_ref == NULL)
    {
        cout<<"List is empty.\n";
    }
    else
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        del = temp;
        temp = *head_ref;
        while (temp->next != del)
        {
            temp = temp->next;
        }
        prev = temp;
        prev->next = *head_ref;
        free(del);
    }
}

void viewNode(struct node **head_ref)
{
    struct node * temp;
    temp = *head_ref;

    if(*head_ref==NULL)
        cout<<"list is empty.\n";
    else
    {
        while (temp->next != *head_ref)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout<<temp->data;
    }
}

int menu()
{
    int ch;
    cout<<"\n\nMenu:"<<endl;
    cout<<"1. Add Data\n";
    cout<<"2. Delete Data\n";
    cout<<"3. View Data\n";
    cout<<"4. Exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    return(ch);
}


int main()
{
    struct node *head = NULL;
    while(1)
    {
        switch (menu())
        {
        case 1:
            createNInsertNode(&head);
            break;
        case 2:
            deleteNode(&head);
            break;
        case 3:
            viewNode(&head);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "You hace entered wrong choice.";
            break;
        }
    }
    return 0;
}