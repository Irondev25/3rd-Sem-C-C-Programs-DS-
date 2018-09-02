#include <stdio.h>

int main()
{
    int transact;
    float amount;
    scanf("%d%f", &transact, &amount);
    if ((transact+0.5) < amount && transact % 5 == 0)
    {
        amount = amount - transact - 0.50;
    }
    printf("%.2f", amount);
    return 0;
}