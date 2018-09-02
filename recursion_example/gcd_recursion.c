#include<stdio.h>


int main(){
    int GCD(int , int);
    int a,b;
    printf("Enter 2 numbers to find its GCD.\n");
    scanf("%d%d", &a, &b);
    printf("GCD of %d and %d is %d", a, b, GCD(a,b));
    return 0;
}

// int GCD(int a, int b){
//      if(a>b){
//          if(a%b!=0)
//              GCD(a%b, b);
//          else
//              return(b);
//      }
//      else if(a<b){
//          if(b%a!=0)
//              GCD(a, b%a);
//          else
//              return(a);
//      }
//      else
//          return(a);
// }

//optimized one

int GCD(int a, int b){
    if(b==0){
        return(a);
    }
    else{
        return GCD(b, a%b);
    }
}