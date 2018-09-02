#include<iostream>

int search_array(int arr[],int a)
{
    for(int i=0; i<6; i++)
    {
        if(arr[i] == a)
        {
            return a;
        }
    }
    return 0;
}

int main()
{
    int a[] = {11, 15, 6, 8, 9, 10}, sum_req, snd_pair;
    scanf("%d", &sum_req);
    for(int i=0; i<6; i++)
    {
        snd_pair = search_array(a ,sum_req-a[i]);
        if(snd_pair!=0)
        {
            printf("\n%d---%d\n", a[i], snd_pair);
        }
    }
    return 0;
}