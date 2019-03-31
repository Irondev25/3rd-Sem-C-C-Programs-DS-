#include<bits/stdc++.h>
using namespace std;

stack <int> s;
int visited[100];
int adj[100][100];

void toposort(int v, int n){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(visited[i]==0 && adj[v][i]){
            toposort(i,n);
        }
    }
    s.push(v);
}

int main(){
    int n;
    cout<<"Enter number of vertices:\n";
    cin>>n;
    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            toposort(i,n);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}