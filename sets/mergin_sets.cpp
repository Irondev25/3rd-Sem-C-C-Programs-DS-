#include <iostream>
#include <algorithm>
using namespace std;

int par[100002];
int sz[100002];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_parent(int mem)
{
    if (par[mem] == mem)
        return mem;
    return par[mem] = find_parent(par[mem]);
}

void Union(int u, int v)
{
    int par_u = find_parent(u);
    int par_v = find_parent(v);
    if (par_u == par_v)
        return;
    par[par_u] = par_v;
    sz[par_v] += sz[par_u];
}

int main()
{
    int n, q, u, v;
    char tq;
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++)
    {
        cin >> tq;
        if (tq == 'Q')
        {
            cin >> u;
            cout << sz[find_parent(u)] << endl;
        }
        else
        {
            cin >> u >> v;
            Union(u, v);
        }
    }
    return 0;
}