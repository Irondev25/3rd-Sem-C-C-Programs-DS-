#include<stdio.h>


int multiply(int num, int fact[], int size){
    int carry=0, prod;
    for(int i=0; i<size; i++){
        prod = fact[i]*num+carry;
        fact[i] = prod%10;
        carry = prod/10;
    }
    while(carry){
        fact[size] = carry%10;
        carry/=10;
        size++;
    }
    return size;
}


void extraLongFactorials(int n){
    int i, fact[10000],size=1;
    fact[0]=1;
    for(i=2; i<n; i++){
        size = multiply(i, fact, size);
    }
    for(i=size-1; i>=0; i--){
        printf("%d", fact[i]);
    }
}

int main(){
    extraLongFactorials(1000);
    return 0;
}