#include<iostream>

using namespace std;

void viewArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void addData(int *arr, int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

int* rotate_array(int *arr, int length, int rot){
    int * new_array = (int *)malloc(length*sizeof(int));
    for(int i=0; i<length; i++){
        new_array[(i+rot)%length] = arr[i];
    } 
    return new_array;
}

int main(){
    int n, rot;
    cout<<"Enter the size of your array:\n";
    cin>>n;
    int *arr = (int *)malloc(sizeof(int)*n);
    addData(arr, n);
    viewArray(arr, n);
    cout<<"Enter the rotation value: ";
    cin>>rot;
    arr = rotate_array(arr, n, rot);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// #include <iostream>

// using namespace std;

// int * rotate_array(int *arr, int length, int rot)
// {
//     int *new_array = (int *)malloc(length * sizeof(int));
//     for (int i = 0; i < length; i++)
//     {
//         new_array[(i + rot) % length] = arr[i];
//     }
//     arr = new_array;
//     free(new_array);
//     return arr;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = sizeof(arr) / sizeof(int), rot;
//     // int *array = arr;
//     cout << "Enter the rotation value: ";
//     cin >> rot;
//     arr = rotate_array(arr, n, rot);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }