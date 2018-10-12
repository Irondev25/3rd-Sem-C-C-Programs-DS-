#include<stdio.h>
#include<stdlib.h>

long combination(int n, int r){
    if(r==n)
        return 1;
    if(r==1){
        return n;
    }
    return combination(n-1, r) + combination(n-1, r-1);
}

int main(int argc, char const *argv[])
{
    printf("%ld",combination(10,4));
    return 0;
}
