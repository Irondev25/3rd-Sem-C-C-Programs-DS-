#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long int selection_sort(int *arr, int n){
    int i,j,min,pos,temp;
    long int basic_op=0;
    for(i=0;i<n-1;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            basic_op++;
            if(arr[j]<arr[pos]){
                pos=j;
            }
        }
        temp=arr[pos];
        arr[pos]=arr[i];
        arr[i]=temp;
    }
    return basic_op;
}

int main(){
    int arr[1000],i,n=10;
    srand(time(0));
    scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("\n");
        selection_sort(arr,n);
        for(i=0;i<n;i++)
            printf("%d ", arr[i]);
        printf("\n");

    return 0;
}