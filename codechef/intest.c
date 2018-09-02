#include<stdio.h>

int main(){
    double n, k, t;
    int count=0;
    scanf("%g%g", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%t", &t);
        if(t%k==0){
            count++;
        }
    }
    return 0;
}