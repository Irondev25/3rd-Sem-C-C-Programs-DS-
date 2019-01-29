#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char string[100] = "NOBODY_NOTICED_HIM";
    char search_string[20];
    int i, j, n, m;
    scanf("%s", search_string);
    for (i = 0; string[i] != '\0'; i++)
        ;
    n = i;
    for (i = 0; search_string[i] != '\0'; i++)
        ;
    m = i;
    printf("%d\t%d\n", n, m);
    for (i = 0; i <= (n - m); i++)
    {
        j = 0;
        while (j < m && (search_string[j] == string[i + j]))
        {
            j++;
        }
        if (j == m)
        {
            printf("String Found!!\n%d", i);
            break;
        }
    }
    return 0;
}