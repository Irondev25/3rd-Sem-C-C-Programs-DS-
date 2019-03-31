#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int visited[100];

queue<int> q;

void bfs(int v,int n){
    int temp;
    visited[v]=1;
    q.push(v);
    cout<<v<<" ";
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==0 && graph[temp][i]==1){
                q.push(i);
                visited[i]=1;
                cout<<i<<" ";
            }
        }
    }
}

void BFS(int n){
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            bfs(i,n);
            cout<<endl;
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of Edges:\n";
    cin>>n;
    cout<<"Enter adjacent Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    cout<<"Graph Traversal\n";
    BFS(n);
    return 0;
}