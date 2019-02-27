#include <iostream>

#define V 5

using namespace std;

int minKey(int key[], bool mstSet[]){
    int min=__INT_MAX__, min_index;
    for(int v=0;v<V;v++){
        if(mstSet[v]==false && key[v]<min)
            min = key[v], min_index=v;
    }
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i]=__INT_MAX__, mstSet[i]=false;
    }

    //include 1st vertex
    key[0]=0;
    parent[0]=-1;


    for(int count=0;count<V-1;count++){
        //pick min vertex from the set not included
        int u = minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
                parent[v]=u,key[v]=graph[u][v];
        }
    }
    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primMST(graph);
    return 0;
}