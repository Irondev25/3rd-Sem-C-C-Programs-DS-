#include<iostream>

using namespace std;

int A[100005]={0};
int last=0;

//void show_heap();

void swap(int& a, int &b){
    int c = a;
    a = b;
    b = c;
}

inline int Parent(int i){
    return i/2;
}

inline int Left(int i){
    return i*2;
}

inline int Right(int i){
    return i*2+1;
}

void min_heap(int i){
    int parent = Parent(i);
    if(i>1 && A[parent]>A[i]){
        swap(A[parent], A[i]);
        min_heap(parent);
    }
}

void max_heap(int i){
    int left=Left(i);
    int right=Right(i);
    int smallest;
    if(left<=last && A[i]>A[left])
        smallest = left;
    else    
        smallest = i;

    if(right<=last && A[smallest]>A[right])
        smallest = right;
    if(smallest!=i){
        swap(A[smallest], A[i]);
        max_heap(smallest);
    }
}

void insert(int data){
    if(last==0){
        last++;
        A[1] = data;
    }
    else{
        ++last;
        A[last] = data;
        min_heap(last);
    }
}

void remove(int data){
    if(last==0){
        exit(0);
    }
    int i=1;
    while(A[i]!=data){
        i++;
    }
    swap(A[i], A[last]);
    --last;
    max_heap(i);
}

void show_heap(){
    for(int i=1; i<=last; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int q, qt, data;
    cin>>q;
    for(int i=1; i<=q; i++){
        cin>>qt;
        switch(qt){
            case 1: cin>>data;
                insert(data);
                break;
            case 2: cin>>data;
                remove(data);
                break;
            case 3: show_heap();
                break;
            default: exit(0);
        }
    }
    return 0;
}