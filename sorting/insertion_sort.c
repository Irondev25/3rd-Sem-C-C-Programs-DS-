#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double count=0;

void insertion_sort(int *arr,int n){
    int i,v,j;
    for(i=1;i<n;i++){
        v=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>v){
            arr[j+1]=arr[j];
            j--;
            count++;
        }
        arr[j+1]=v;
    }
}

int main(){
    srand(time(0));
    double test = 10;
    long int n, i;
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
        count = 0;
        insertion_sort(asc, n);
        printf("%lf \n", count);
        count = 0;
        insertion_sort(dsc, n);
        printf("%lf \n", count);
        printf("BO/n*n: %lf\n", (double)count / (n * n));
        count = 0;
        insertion_sort(random, n);
        printf("%lf \n", count);
        printf("BO/n*n: %lf\n", (double)count / (n * n));
        test *= 10;
        printf("\n\n");
    }

    return 0;
}