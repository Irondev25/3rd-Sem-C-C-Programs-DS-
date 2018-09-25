#include <stdio.h>
int main()
{

    int i, j, a, n=10000, number[10000];
    FILE *in_file = fopen("random_input.txt", "r");
    for (i = 0; i < n; ++i){
        fscanf(in_file, "%d", &number[i]);
    }
    printf("\n\nScan Complete\n\n");
    for (i = 0; i < n; ++i)
    {

        for (j = i + 1; j < n; ++j)
        {

            if (number[i] > number[j])
            {

                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
        printf("Sorting %d\n", i);
    }

    FILE *out_file = fopen("random.txt", "w");

    printf("The numbers arranged in ascending order are given below \n");
    for (i = 0; i < n; ++i)
        fprintf(out_file, "%d ", number[i]);
    return 0;
}