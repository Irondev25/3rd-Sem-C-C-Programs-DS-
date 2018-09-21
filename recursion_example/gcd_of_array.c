#include<stdio.h>


int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int gcd_of_array(int length ,int *a){
    int i;
    for (i = 0; i < (length-1); i++){
        a[i + 1] = gcd(a[i], a[i + 1]);
    }
    return a[i];
}

int main(){
    int a[] = {16,32,96};
    printf("GCD of {16,32,96} is %d", gcd_of_array(3, a)); 
    return 0;
}