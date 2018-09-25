//https://www.hackerrank.com/challenges/magic-square-forming/problem
#include <stdio.h>
#include <stdlib.h>

int formingMagicSquare(int s_rows, int s_columns, int s[3][3])
{
    int ms[8][3][3] = {
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}};
    int cost, min = 100;
    for (int k = 0; k < 8; k++)
    {
        cost = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cost += abs(ms[k][i][j] - s[i][j]);
            }
        }
        if (cost < min)
            min = cost;
    }
    return min;
}

int main()
{
    int a[][3] = {{4, 8, 2}, {4, 5, 7}, {6, 1, 6}};
    int min = formingMagicSquare(3, 3, a);
    printf("Cost: %d\n", min);
    return 0;
}