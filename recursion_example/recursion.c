#include<stdio.h>
#include<conio.h>

int main(){
    int add(int);
    int k;
    printf("Enter any number:\n");
    scanf("%d", &k);
    printf("Sum of 1st %d natural numbers is %d", k, add(k));
    return 0;
}

int add(int a){
    int s=1;
    if(a==1)
        return(a);
    s = a + add(a-1);
    return(s);
}