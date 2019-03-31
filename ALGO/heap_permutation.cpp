#include<iostream>
#include<algorithm>

using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void heap_perm(int *a, int size,int n){
    if(size==1){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        heap_perm(a,size-1,n);
        if(size%2==1){
            swap(a[0],a[size-1]);
        }
        else{
            swap(a[i],a[size-1]);
        }
    }
}

int main(){
    int a[]={1,2,3};
    heap_perm(a,3,3);
    return 0;
}