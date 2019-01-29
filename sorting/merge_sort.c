#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* merge(int *left, int* right, int *arr, int l, int r, int a){
    int i, j, k;
    i=0;
    j=0;
    k=0;
    while(i<l && j<r){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<l){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<r){
        arr[k]=right[j];
        k++;
        j++;
    }
    return arr;
}

int* merge_sort(int* arr, int len){
    int mid, i, left[len/2+1], right[len/2+1], j, ll, rl;
    if(len<2)
        return NULL;
    mid=len/2;
    for(i=0; i<mid; i++){
        left[i]=arr[i];
    }
    j=0;
    for(i=mid; i<len; i++){
        right[j]=arr[i];
        j++;
    }
    if(len%2==0){
        merge_sort(left, mid);
        merge_sort(right, mid);
        ll=mid;
        rl=mid;
    }
    else{
        merge_sort(left, mid);
        merge_sort(right, mid+1);
        ll=mid;
        rl=mid+1;
    }
    arr=merge(left, right, arr, ll, rl,len);
    return arr;
}

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double run_time, avg=0, max=0, min=500;
    int arr[100000], i,j;
    int *ar, t;
    srand(time(0));
    int n;
    scanf("%d%d", &n, &t);
    for(j=0; j<t; j++){
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 100000;
            // printf("%d ", arr[i]);
        }
        start = clock();
        ar = merge_sort(arr, n);
        end = clock();
        run_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        //printf("time: %lf\n", run_time);
        avg+=run_time;
        if(run_time>max)
            max=run_time;
        if(run_time<min)
            min=run_time;
    }
    printf("AVERAGE TIME: %lf\tMAX TIME: %lf\tMIN TIME%lf\n", avg/t, max, min);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    return 0;
}

//AVERAGE TIME: 0.020707	MAX TIME: 0.048436	MIN TIME0.020138 for 100000 size and 100000 runs
//AVERAGE TIME: 0.020797	MAX TIME: 0.046560	MIN TIME0.020183 for 100000 size and 10 runs
//AVERAGE TIME: 0.000748	MAX TIME: 0.000903	MIN TIME0.000610 for 1000 size and 10 runs
//AVERAGE TIME: 0.000456    MAX TIME : 0.000864 MIN TIME0 .000172  for 1000 size and 100 runs
//AVERAGE TIME: 0.000169	MAX TIME: 0.000814	MIN TIME0.000137 for 1000 size and 1000 runs
//AVERAGE TIME: 0.000144	MAX TIME: 0.000812	MIN TIME0.000137 for 1000 size and 10000 runs
//AVERAGE TIME: 0.000141	MAX TIME: 0.000852	MIN TIME0.000137 for 1000 size and 100000 runs
