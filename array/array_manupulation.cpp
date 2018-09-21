//     https://www.hackerrank.com/challenges/crush/problem

#include <iostream>
using namespace std;


long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long *a = (long *)calloc(n,sizeof(long)),i, j=0,max=0;
    for(i=0; i<queries_rows; i++){
        a[queries[i][0]-1]+=queries[i][2];
        if((queries[i][1]+1)<=n)
            a[queries[i][1]]-=queries[i][2];
    }
    for(i=0;i<n;i++){
        j=j+a[i];
        if(max<j)
            max=j;
    }
    return max;
}


int main() {
    int n=4, rows=3, col=3, i, j;
    int **queries = (int **)calloc(rows, sizeof(int));
    for(i=0; i<rows; i++){
        queries[i] = (int *)calloc(col, sizeof(int));
        for(j=0; j<col; j++){
            cin>>queries[i][j];
        }
    }
    cout<<endl;
    for(i=0; i<rows; i++){
        for(j=0; j<col; j++){
            cout<<queries[i][j];
        }
        cout<<endl;
    }
    cout<<"MAX: "<<arrayManipulation(n, rows, col, queries);
    return 0;
}