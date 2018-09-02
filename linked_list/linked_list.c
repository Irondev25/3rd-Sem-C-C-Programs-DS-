#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

//starting pointer
struct node *START = NULL;

void viewList();

//function to create new node data type
struct node *createNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return (n);
}

void insertNode()
{
    struct node *temp, *t;
    temp = createNode();
    printf("Enter a number:\t");
    scanf("%d", &temp->info);
    temp->link = NULL;
    if (START == NULL)
    {
        START = temp;
    }
    else
    {
        t = START;
        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

void deleteNode()
{
    struct node *r;
    if (START == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        r=START;
        START=START->link;
        free(r);
    }
}

void IndexBasedDelete()
{
    int index, i=1;
    struct node *temp = START, *del, *join;
    if(START == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Enter the index you want to delete(1 based index):\n");
        scanf("%d", &index);
        while (i < index - 1)
        {
            temp = temp->link;
            i++;
        }
        del = temp->link;
        join = del->link;
        temp->link = join;
        free(del);
        viewList();
    }
}


void viewList(){
    struct node *t;   
    if(START==NULL)
        printf("List is empty");
    else
    {
        t=START;
        while(t!=NULL)
        {
            printf("%d ", t->info);
            t=t->link;
        }
    }
}

int menu(){
    int ch;
    printf("\n\n1. Add value to the list.");
    printf("\n2. Delete first value.");
    printf("\n3. View list.");
    printf("\n4. Delete a particular node.");
    printf("\n5. Exit\n");
    printf("Enter a choice:\t");
    scanf("%d", &ch);
    return ch;
}

int main()
{   
    while(1){
        switch(menu()){
            case 1: insertNode();
                break;
            case 2: deleteNode();
                break;
            case 3: viewList();
                break;
            case 4: IndexBasedDelete();
                break;
            case 5: exit(0);
                break;
            default : printf("Invalid choice.");
        }
    }
}