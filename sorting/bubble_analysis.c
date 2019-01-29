#include<stdio.h>
#include<stdlib.h>
#include<time.h>


double bubble_sort(int *arr, int len){
    int i, swap=1, last=len-2, temp, swapped=0;
    while(swap!=0){
        swap=0;
        for(i=0; i<=last; i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
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

int main(){
    srand(time(0));
    double test=10;
    clock_t start, end;
    double time_taken;
    int n, i;
    int asc[100000], dsc[100000], random[100000];
    int *arr;
    while(test<=100000){
        printf("TESTING FOR N=%lf\n", test);
        n=test;
        for (i = 0; i < n; i++)
        {
            asc[i] = i + 1;
            dsc[i] = n - i;
            random[i] = rand() % (10 * n);
        }
        start = clock();
        printf("%lf swaps\n", bubble_sort(asc, n));
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("TIME TAKEN: %lf\n", time_taken);
        start = clock();
        printf("%lf swaps\n", bubble_sort(dsc, n));
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("TIME TAKEN: %lf\n", time_taken);
        start = clock();
        printf("%lf swaps\n", bubble_sort(random, n));
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("TIME TAKEN: %lf\n", time_taken);
        test*=10;
        printf("\n\n");
    }
    return 0;
}