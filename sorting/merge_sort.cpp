#include <iostream>

using namespace std;

long int count = 0;

void merge(int a[], int low, int high, int mid)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100000];
    while (i <= mid && j <= high)
    {
        count++;
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid)
    {
        count++;
        temp[k++] = a[i++];
    }
    while (j <= high)
    {
        count++;
        temp[k++] = a[j++];
    }
    i = low;
    k = 0;
    while (i <= high)
    {
        a[i++] = temp[k++];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

int main(int argc, char const *argv[])
{
    for (int t = 10; t <= 100000; t = t * 10)
    {
        int asc[t], dsc[t], random[t];
        for (int i = 0; i < t; i++)
        {
            asc[i] = i + 1;
            dsc[i] = t - i;
            random[i] = rand() % (t * 10);
        }
        count = 0;
        merge_sort(asc, 0, t - 1);
        cout << "ASC: " << count << endl;
        count = 0;
        merge_sort(dsc, 0, t - 1);
        cout << "DSC: " << count << endl;
        count = 0;
        merge_sort(random, 0, t - 1);
        cout << "Random: " << count << endl;
    }
    return 0;
}

//AVERAGE TIME: 0.020707	MAX TIME: 0.048436	MIN TIME0.020138 for 100000 size and 100000 runs
//AVERAGE TIME: 0.020797	MAX TIME: 0.046560	MIN TIME0.020183 for 100000 size and 10 runs
//AVERAGE TIME: 0.000748	MAX TIME: 0.000903	MIN TIME0.000610 for 1000 size and 10 runs
//AVERAGE TIME: 0.000456    MAX TIME : 0.000864 MIN TIME0 .000172  for 1000 size and 100 runs
//AVERAGE TIME: 0.000169	MAX TIME: 0.000814	MIN TIME0.000137 for 1000 size and 1000 runs
//AVERAGE TIME: 0.000144	MAX TIME: 0.000812	MIN TIME0.000137 for 1000 size and 10000 runs
//AVERAGE TIME: 0.000141	MAX TIME: 0.000852	MIN TIME0.000137 for 1000 size and 100000 runs
