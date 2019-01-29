#include <stdio.h>
#include <stdlib.h>

int heap[100001] = {0};
int last = 0;

void show();

int Parent(int i)
{
    return (i / 2);
}

int Left(int i)
{
    return 2 * i;
}

int Right(int i)
{
    return 2 * i + 1;
}

void bubble_up(int i)
{
    int p = Parent(i), temp;
    if (i > 0 && i <= last && heap[i] > heap[p])
    {
        temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        if (p != 1)
            bubble_up(p);
    }
    else
    {
        return;
    }
}

void bubble_down(int i, int s_last)
{
    int l = Left(i);
    int r = Right(i);
    int largest, temp;
    if (l <= s_last && heap[i] < heap[l])
    {
        largest = l;
    }
    else
        largest = i;
    if (r <= s_last && heap[r] > heap[largest])
        largest = r;

    if (largest != i)
    {
        temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;
        bubble_down(largest, s_last);
    }
}

void heap_sort()
{
    int temp, i, s_last = last;
    if (s_last == 0)
        return;
    while (s_last != 0)
    {
        //printf("%d %d", heap[s_last], heap)
        temp = heap[s_last];
        heap[s_last] = heap[1];
        heap[1] = temp;
        --s_last;
        bubble_down(1, s_last);
    }
    show();
}

void insert(int data)
{
    if (last == 0)
    {
        last++;
        heap[1] = data;
        return;
    }
    if (last != (100000))
    {
        ++last;
        heap[last] = data;
        bubble_up(last);
    }
}

void show()
{
    int i = 0;
    for (i = 1; i <= last; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main()
{
    int i;
    for (i = 1; i <= 100; i++)
        insert(i);
    show();
    heap_sort();
    printf("DONE\n");
    return 0;
}