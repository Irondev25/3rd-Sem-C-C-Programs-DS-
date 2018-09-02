#include<stdio.h>
#include<math.h>

int main(){
    void TOH(int , char, char, char);
    int n;
    printf("Enter the number of discs:\t");
    scanf("%d", &n);
    TOH(n, 'a', 'b', 'c');
    printf("Their will be total %g steps", pow(2,n) - 1);
    return 0;
}

void TOH(int n, char BEG, char AUX, char END){
    if(n>=1){
        TOH(n-1, BEG, END, AUX);
        printf("%c to %c\n", BEG, END);
        TOH(n-1, AUX, BEG, END);
    }
}