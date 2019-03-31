#include<iostream>
#include<algorithm>

using namespace std;

int adj[100][100];

void dfs(int s, bool* visited, int n){
    if(visited[s]==false){
        cout<<s+1<<" ";
        visited[s]=true;
        for(int i=0;i<n;i++){
            if(adj[s][i]==1 && visited[i]==false){
                dfs(i,visited,n);
            }
        }
    }
}

// int main(){
//     int n;
//     cin>>n;
//     bool visited[n],connect=false;
//     fill(visited,visited+n,false);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>adj[i][j];
//         }
//     }
//     int i=0;
//     while(connect==false){
//         graphs++;
//         connect=true;
//         path=0;
//         dfs(i, visited, n);
//         graph[graphs-1]=path;
//         cout << endl;
//         for (i = 0; i < n; i++)
//         {
//             if (!visited[i])
//             {
//                 connect = false;
//                 break;
//             }
//         }
//     }
//     path=0;
//     for(int i=0;i<graphs;i++){
//         path+=(graph[i]-1);
//     }
//     cout<<"path length"<<path<<endl;
//     return 0;
// }

int main(){
    int n;
    cout<<"Enter number of vertices:\n";
    cin>>n;
    bool visited[n]={0};
    cout<<"Enter adjacent matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i,visited,n);
            cout<<endl;
        }
    }
    return 0;
}