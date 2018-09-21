//https://www.hackerrank.com/challenges/the-birthday-bar/problem
#include <stdio.h>
#include <time.h>

int getSum(int *a, int start, int end)
{
    int sum = 0, i;
    for (i = start; i < end; i++)
    {
        sum += a[i];
    }
    return sum;
}

int birthday(int s_count, int *s, int d, int m)
{

    int count = 0, i;
    for (i = 0; i <= (s_count - m); i++)
    {
        if (getSum(s, i, i + m) == d)
            count++;
    }
    return count;
}

int birthdayFast(int s_count, int *s, int d, int m)
{
    int i,sum[105], count=0;
    sum[0] = 0;
    for(i=0; i<s_count; i++){
        sum[i+1]=sum[i]+s[i];
    }
    for(i=0; i<=(s_count-m); i++){
        if(sum[i+m]-sum[i]==3)
            count++;
    }
    return count;
}

int main()
{
    clock_t start, end;
    double time_taken=0;
    int a[] = {1, 2, 1, 3, 2}, count;
    start = clock();
    count = birthday(5, a, 3, 2);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Slow Version: %d with %f sec\n", count, time_taken);
    start = clock();
    count = birthdayFast(5, a, 3, 2);
    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Fast Version: %d with %f sec\n", count, time_taken);
    return 0;
}