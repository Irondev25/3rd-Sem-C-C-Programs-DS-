#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFSUtil(int, bool*);
    void DFS(int);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    list<int> queue;

    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

int main()
{
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5,6);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 1) \n";
    g.BFS(1);
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 1) \n";
    g.DFS(1);
    return 0;
}