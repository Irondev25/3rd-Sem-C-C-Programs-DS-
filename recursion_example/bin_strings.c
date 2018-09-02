#include <stdio.h>

void binary(char A[], int n)
{
    if (n < 1)
        printf("%s\n", A);
    else
    {
        A[n - 1] = '0';
        binary(A, n - 1);
        A[n - 1] = '1';
        binary(A, n - 1);
    }
}

int main(void)
{
    char A[10]={'\0'};
    binary(A, 3);
    return 0;
}