#include<iostream>
#include<algorithm>

using namespace std;

int adj[100][100];

void dfs(int s, bool* visited, int n){
    if(visited[s]==false){
        cout<<(char)(s+65)<<" ";
        visited[s]=true;
        for(int i=0;i<n;i++){
            if(adj[s][i]==1 && visited[i]==false){
                dfs(i,visited,n);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    bool visited[n];
    fill(visited,visited+n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    dfs(0,visited,n);
    return 0;
}