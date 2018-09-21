#include<stdio.h>


int GCD(int a, int b){
    if(b==0)
        return a;
    return GCD(b, a%b);
}


int LCM(int a, int b){
    return (a*b)/GCD(a,b);
}


int LCM_of_array(int length, int *a){
    int i;
    for(i=0; i<(length-1); i++){
        a[i+1] = LCM(a[i], a[i+1]);
    }
    return a[i];
}


int main(){
    int a[] = {2,4}; 
    printf("LCM: %d\n", LCM_of_array(2, a));
    return 0;
}