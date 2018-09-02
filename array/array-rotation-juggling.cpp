#include<iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, b%a);
}


void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < gcd(d, n); i++)
    {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
        printArray(arr, n);
        printf("\n");
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 12, n);
    printArray(arr, n);
    return 0;
}