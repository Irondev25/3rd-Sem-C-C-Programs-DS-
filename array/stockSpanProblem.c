//its a naive approach to stockSpan problem
// https://www.geeksforgeeks.org/the-stock-span-problem/

#include<stdio.h>

void stockSpan(int *a){
    int i, j, ss[7] = {0};
    ss[0] = 1;
    for(i=1; i<7; i++){
        ss[i]++;
        for(j=i; j<7; j++){
            if(a[j]>a[i])
                ++ss[j];
        }
    }
    for(i=0; i<7; i++){
        printf("%d ", ss[i]);
    }
}

int main(){
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    stockSpan(arr);
    return 0;
}