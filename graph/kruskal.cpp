#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cout<<"Enter number of edges: "<<endl;
    cin>>nodes;
    int matrix[nodes][nodes];
    edges=0;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin>>matrix[i][j];
            if(j<i && matrix[i][j]!=0){
                p[edges]=make_pair(matrix[i][j],make_pair(i,j));
                edges++;
            }
        }
    }
    sort(p, p + edges);
    // for (int i=0;i<edges;i++)
    // {
    //     cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
    // }
    minimumCost = kruskal(p);
    cout <<"Minimum Cost: "<< minimumCost << endl;
    return 0;
}