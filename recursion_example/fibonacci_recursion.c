#include<stdio.h>

int main(){
    double fibonacci(int n);
    int n;
    printf("Enter number upto which fibonacci series required.\n");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printf("%g\t", fibonacci(i));
    }
    return 0;
}

double fibonacci(int n){
    if (n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}