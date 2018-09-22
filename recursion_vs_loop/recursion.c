#include <stdio.h>
#include <time.h>

int binary_search(int *a, int initial, int final, int data)
{
    int middle = (initial + final) / 2;
    if (a[middle] == data)
        return middle;
    else if (initial == final)
        return -1;

    if (data < a[middle])
        return binary_search(a, initial, middle - 1, data);
    else
        return binary_search(a, middle + 1, final, data);
}

int main()
{
    clock_t start, end;
    double speed;
    int arr[10000];
    int x=31949, search;
    FILE *input = fopen("random.txt", "r");
    for(int i=0; i<10000; i++){
        fscanf(input,"%d ", &arr[i]);
    }
    fclose(input);
    printf("Scanned Completely\n");
    start = clock();
    search = binary_search(arr, 0, 9999, x);
    end = clock();
    speed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("The function completed in %f sec\n", speed);
    if (search != -1)
        printf("%d found at %d place\n", arr[search], search + 1);
    else
        printf("%d number not found\n", x);
    return 0;
}