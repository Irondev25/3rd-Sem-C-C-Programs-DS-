#include<stdio.h>
#include<conio.h>

int main(){
    double factorial(int);
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    printf("Factorial of %d is %g", n, factorial(n));
    return 0;
}

double factorial(int n){
    int f = 1;
    if (n == 1){
        return n;
    }
    f = n * factorial(n-1);
    return f;
}