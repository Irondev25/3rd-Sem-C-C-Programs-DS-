#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

long int count=0;

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int _partition(int arr[], int low, int high){
    int pivot=arr[low],i=low,j=high,temp;
    while(1){
        while(i<=high && arr[i]<=pivot){
            i++;
            count++;
        }
        while(arr[j]>pivot){
            j--;
            count++;
        }
        if (i >= j)
        {
            break;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void _quick_sort(int arr[], int low, int high){
    if(low<high){
        int pivot=_partition(arr,low,high);
        _quick_sort(arr,low,pivot-1);
        _quick_sort(arr,pivot+1,high);
    }
}

void quick_sort(int arr[],int n){
    _quick_sort(arr,0,n-1);
}

// int main()
// {
//     srand(time(0));
//     int arr[100000], i, n;
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         arr[i] = rand() % (n * 10);
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     quick_sort(arr, n);
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

int main()
{
    srand(time(0));
    double test = 10;
    int n, i;
    int asc[100000], dsc[100000], random[100000];
    while (test <= 100000)
    {
        printf("TESTING FOR N=%lf\n", test);
        n = test;
        for (i = 0; i < n; i++)
        {
            asc[i] = i + 1;
            dsc[i] = n - i;
            random[i] = rand() % (10 * n);
        }
        count=0;
        quick_sort(asc, n);
        printf("%ld \n", count);
        count=0;
        quick_sort(dsc, n);
        printf("%ld \n", count);
        printf("ASC&DSC: %lf\n",(double)count/(n*n));
        count=0;
        quick_sort(random, n);
        printf("%ld \n", count);
        printf("RANDOM: %lf\n",(double)count/(n*log10(n)));
        test *= 10;
        printf("\n\n");
    }
    return 0;
}