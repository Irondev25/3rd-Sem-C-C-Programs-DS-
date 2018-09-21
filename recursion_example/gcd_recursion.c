#include<stdio.h>


int main(){
    int GCD(int , int);
    int GCDof3Num(int, int, int);
    printf("%d",GCDof3Num(16, 32, 96));
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

int GCDof3Num(int a, int b, int c){
    return GCD(GCD(a,b),c);
}