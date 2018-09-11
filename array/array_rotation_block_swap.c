#include<stdio.h>


void print_array(int *a, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int *a, int start, int last){
    int i, j;
    for(i=start, j=last; i<j; i++,j--){
        swap(&a[i], &a[j]);
    }
}


void rotate_array(int *a, int l,int n){
    reverse_array(a, 0, l-1);
    reverse_array(a, l, n-1);
    reverse_array(a, 0 , n-1);
}


int main(){
    int arr[100000], n, d, i;
    scanf("%d%d", &n, &d);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    rotate_array(arr, d, n);
    print_array(arr, n);
    return 0;
}
