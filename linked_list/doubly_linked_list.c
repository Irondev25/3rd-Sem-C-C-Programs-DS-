#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};

struct node* START=NULL;

void insertAsFirstNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter a number:\t");
    scanf("%d", &n->info);
    n->prev=NULL;
    n->next=NULL;
    if(START==NULL)
    {
        START=n;
    }
    else
    {
        START->prev = n;
        n->next = START;
        START = n;
    }
}

void deleteFirstNode()
{
    struct node * r;
    if(START == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        r = START;
        START = START->next;
        START->prev = NULL;
        free(r);
    }
}

void viewList()
{
    struct node *t;
    if(START==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        t = START;
        while(t->next != NULL)
        {
            printf("%d", t->info);
            t=t->next;
        }
    }
}

int menu()
{
    int ch;
    printf("\n\nMenu:\n");
    printf("1. Add Data to list.\n");
    printf("2. Delete Data\n");
    printf("3. Display Data.\n");
    printf("4. Exit\n");
    printf("Enter your choice:\t");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    while(1)
    {
        switch (menu())
        {
        case 1:
            insertAsFirstNode();
            break;
        case 2:
            deleteFirstNode();
            break;
        case 3:
            viewList();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice.");
            break;
        }
    }
    return 0;
}

