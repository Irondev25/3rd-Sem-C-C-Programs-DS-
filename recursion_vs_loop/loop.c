#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    int c, first, last, middle, n=10000, search=31949, array[10000];

    FILE *input = fopen("random.txt", "r");

    for (c = 0; c < n; c++)
        fscanf(input, "%d", &array[c]);

    printf("Scaning Complete..\n\n");

    start = clock();

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search)
        {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d isn't present in the list.\n", search);
    
    end = clock();

    double exe_time = ((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("Total Time taken :%f", exe_time);

    return 0;
}