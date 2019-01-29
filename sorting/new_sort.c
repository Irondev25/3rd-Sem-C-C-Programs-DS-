#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *sortin(int *arr, int len)
{
    int sort_freq[1000000] = {0};
    int i, j = 0;
    int max = 0;
    for (i = 0; i < len; i++)
    {
        sort_freq[arr[i]] = 1;
        if (arr[i] > max)
            max = arr[i];
    }
    for (i = 0; i <= max; i++)
    {
        if (sort_freq[i] >= 1)
        {
            arr[j] = i;
            j++;
        }
    }
    return arr;
}

double bubble_sort(int *arr, int len)
{
    int i, swap = 1, last = len - 2, temp, swapped = 0;
    while (swap != 0)
    {
        swap = 0;
        for (i = 0; i <= last; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap++;
                swapped++;
            }
        }
        last--;
    }
    // for(i=0; i<len; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    return swapped;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    srand(time(0));
    double test = 10;
    clock_t start, end;
    double time_taken;
    int n, i, j;
    int random[100000];             //asc[100000], dsc[100000]
    int *arr;
    scanf("%d", &n);
    for(j=0; j<10; j++){
        for (i = 0; i < n; i++)
        {
            // asc[i] = i + 1;
            // dsc[i] = n - i;
            random[i] = rand() % 1000000;
        }
        start = clock();
        arr = sortin(random, n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTIME TAKEN: %lf\t", time_taken);
        // for (i = 0; i < n; i++)
        // {
        //     printf("%d ", arr[i]);
        // }
        start = clock();
        mergeSort(random, 0, n - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("TIME TAKEN: %lf\n", time_taken);
    }
    return 0;
}