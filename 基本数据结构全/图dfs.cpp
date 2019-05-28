#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int G[maxn][maxn];
int vis[maxn];
int node,edge;

void dfs (int n)
{
    vis[n] = 1;
    cout << n <<endl;
    for (int i = 0; i < node; i++)
    {
        if (G[n][i] && !vis[i])
            dfs(i);
    }
}

int main()
{
    memset (G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    cin >> node;
    int in,out;
    for (int i = 0; i < node; i++)
    {
        cin >> in >> out;
        G[in][out] = G[out][in] = 1;
    }
    dfs(1);
    return 0;
}