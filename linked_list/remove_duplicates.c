#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicatesUtil(node *head, node *prev, int data)
{
    node *curr = head, *previous = prev;
    while (curr != NULL)
    {
        if (curr->data == data)
        {
            previous->next = curr->next;
            free(curr);
            curr = previous->next;
            printf("double yeah\n");
        }
        else
        {
            prev = curr;
            curr = curr->next;
            printf("Hell yeah\n");
        }
    }
}

node *removeDuplicates(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        removeDuplicatesUtil(temp->next, temp, temp->data);
        temp = temp->next;
    }
    return head;
}

void insertAtEnd(node **head_ref, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
    {
        node *end = *head_ref;
        while (end->next != NULL)
            end = end->next;
        end->next = new_node;
    }
}

void createLinkedList(node **head_ref)
{
    int x;
    printf("Enter Data(0 to exit): ");
    scanf("%d", &x);
    while (x != 0)
    {
        insertAtEnd(head_ref, x);
        printf("Enter Data(0 to exit): ");
        scanf("%d", &x);
    }
}

int lengthOfLinkedList(node *head)
{
    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int main()
{
    node *start = NULL;
    createLinkedList(&start);
    printf("%d\n", 90);
    start = removeDuplicates(start);
    printf("%d\n", 92);
    display(start);
    return 0;
}