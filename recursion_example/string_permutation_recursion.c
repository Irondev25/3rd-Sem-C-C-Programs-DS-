#include<stdio.h>

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void permutation(char *s, int i, int n){
    static int count;
    int j;
    if(i==n){
        count++;
        printf("%d. %s\n", count, s);
    }
    else{
        for(j=i; j<=n; j++){
            swap(s+i, s+j);
            permutation(s, i+1, n);
            swap(s+i, s+j);
        }
    }
}

int main(){
    char s[20];
    int l;
    printf("Enter a string:\n");
    scanf("%s", s);
    for(l=0;s[l]!='\0';l++);
    permutation(s, 0, l-1);
    return 0;
}