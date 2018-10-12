#include<stdio.h>
#include<stdlib.h>


double ackermann_fun(int m, int n){
    if(m<0||n<0){
        printf("m, n can't be -ve");
        exit(0);
    }
    if(m==0)
        return n+1;
    if(m>0&&n==0){
        return ackermann_fun(m-1,1);
    }
    else
        return ackermann_fun(m - 1, ackermann_fun(m, n - 1));
}


int main(){
    printf("%lf", ackermann_fun(0,3));
    return 0;
}