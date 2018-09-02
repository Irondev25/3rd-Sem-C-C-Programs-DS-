#include <iostream>
#include <malloc.h>

using namespace std;

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
    cout<<"Enter a number:\t";
    cin>>temp->info;
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
    viewList();
}

int lengthOfNode()
{
    struct node *temp = START;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

struct node * getNodeByData(int a)
{
    struct node *temp = START;
    while(temp!=NULL)
    {
        if(temp->info == a)
        {
            return temp;
        }
        temp=temp->link;
    }
}

bool checkIfHead(struct node *a)
{
    if(START == a)
        return true;
    return false;
}

bool checkIfTail(struct node *a)
{
    if(a->link==NULL)
    {
        return true;
    }
    return false;
}

struct node *getPrevNode(struct node *a)
{
    struct node *temp = START;
    while(temp->link != a)
        temp = temp->link;
    return temp;
}

void deleteNode()
{
    struct node *r;
    if (START == NULL)
    {
        cout<<"List is empty.";
    }
    else
    {
        r = START;
        START = START->link;
        free(r);
    }
    viewList();
}

void IndexBasedDelete()
{
    int index, i = 1;
    struct node *temp = START, *del, *join;
    if (START == NULL)
    {
        cout<<"List is empty.\n";
    }
    else
    {
        cout<<"Enter the index you want to delete(1 based index):\n";
        cin>>index;
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

void viewList()
{
    struct node *t;
    if (START == NULL)
        cout<<"List is empty";
    else
    {
        t = START;
        while (t != NULL)
        {
            cout<<t->info<<" ";
            t = t->link;
        }
    }
}

void reverseList()
{
    struct node *current=START, *prev=NULL, *next=NULL;
    if(START==NULL)
        cout<<"List is empty.\n";
    else
    {
        while(current != NULL)
        {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        START = prev;
    }
    viewList();
}

void searchList()
{
    struct node* temp = START;
    int data, found;
    cout<<"Enter the data to search: ";
    cin>>data;
    while(temp->link != NULL)
    {
        if(temp->info == data)
        {
            found = 1;
            break;
        }
        temp = temp->link;
    }
    if(temp->info == data)
        found =1;
    if(found==1)
    {
        cout<<"Data found in the list.\n";
    }
    else
    {
        cout<<"Data was not in the list.\n";
    }
}

bool searchList(int data)
{
    struct node *temp = START;
    int found;
    while (temp->link != NULL)
    {
        if (temp->info == data)
        {
            found = 1;
            break;
        }
        temp = temp->link;
    }
    if (found == 1)
    {
       return true;
    }
    else
    {
        return false;
    }
}

void swapNode()
{
    struct node *tempa, *tempb, *prev = START, *a, *b, *temp, *prev2;
    int x, y;
    cout<<"Enter data to swap: ";
    cout<<"Enter 1st data: ";
    cin>>x;
    cout<<"Enter 2nd data: ";
    cin>>y;
    if(searchList(x) && searchList(y))
    {
        cout<<"\n\nSwapping.....\n\n";
        a = getNodeByData(x);
        b = getNodeByData(y);
        if(checkIfHead(b))
        {
            temp = a;
            a = b;
            b = temp;
        }
        if(checkIfTail(a))
        {
            temp = a;
            a = b;
            b = temp;
        }
        if(checkIfHead(a))
        {
            if(checkIfTail(b)){
                prev = getPrevNode(b);
                START = b;
                b->link = a->link;
                a->link = NULL;
                prev->link = a;
            }
            else
            {
                prev = getPrevNode(b);
                START = b;
                tempa = a->link;
                tempb = b->link;
                b->link = tempa;
                a->link = tempb;
                prev->link = a;
            }
        }
        else
        {
            if(checkIfTail(b))
            {
                prev = getPrevNode(a);
                prev2 = getPrevNode(b);
                prev->link = b;
                prev2->link = a;
                tempa = a->link;
                b->link = tempa;
                a->link = NULL;
            }
            else
            {
                prev = getPrevNode(a);
                prev2 = getPrevNode(b);
                prev->link = b;
                
                prev2->link = a;
                tempa = a->link;
                tempb = b->link;
                a->link = tempb;
                b->link = tempa;
            }
        }
        cout << "\n";
        viewList();
    }
    else
    {
        cout<<"x or y may not be present in the list.";
    }
}

int menu()
{
    int ch;
    cout<<"\n\n1. Add value to the list.";
    cout<<"\n2. Delete first value.";
    cout<<"\n3. View list.";
    cout<<"\n4. Delete a particular node.";
    cout<<"\n5. Reverse the node.";
    cout<<"\n6. Search the list.";
    cout<<"\n7. Swap 2 Node.";
    cout<<"\n8. Exit.";
    cout<<"\nEnter a choice:\t";
    cin>>ch;
    return ch;
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            viewList();
            break;
        case 4:
            IndexBasedDelete();
            break;
        case 5:
            reverseList();
            break;
        case 6: 
            searchList();
            break;
        case 7: 
            swapNode();
            break;
        case 8:
            exit(0);
            break;
        default:
            cout<<"Invalid choice.";
        }
    }
    return 0;
}
