#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

int *sortArray(int *array, int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < (length - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}

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
    display(*head_ref);
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

void sortLinkedList(node **head_ref)
{
    int length = lengthOfLinkedList(*head_ref), i = 0;
    int *arr = (int *)malloc(sizeof(int) * length);
    node *temp = *head_ref;
    while (temp != NULL)
    {
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    };
    arr = sortArray(arr, length);
    temp = *head_ref;
    i = 0;
    while (temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
}

void mergeLinkedList(node **head_ref1, node **head_ref2)
{
    node *end = *head_ref1;
    while (end->next != NULL)
        end = end->next;
    end->next = *head_ref2;
    sortLinkedList(head_ref1);
    display(*head_ref1);
}

int main()
{
    double fun_time;
    clock_t start, end;
    node *start1 = NULL, *start2 = NULL;
    createLinkedList(&start1);
    createLinkedList(&start2);
    start = clock();
    mergeLinkedList(&start1, &start2);
    end = clock();
    fun_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f", fun_time);
    return 0;
}