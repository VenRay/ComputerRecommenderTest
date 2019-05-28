#include <iostream>
#include <queue>
using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int G[maxn][maxn];
int vis[maxn];
int node,edge;

void bfs (int n)
{
    queue<int> q;
    cout << n <<endl;
    int num = 1,top;
    vis[n] = 1;
    for (int i = 0; i < node ;i++ ) 
    {
        if(G[n][i] == 1 && !vis[i]){
            q.push(i);
            vis[i] = 1;
        }
    }
    while (num < node)
    {
        top = q.front();
        q.pop();
        num++;
        cout <<top<<endl;
        for (int i = 0; i < node; i++)
        {
            if(G[top][i] == 1 && !vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
//q.front() 返回第一个元素(队顶元素)
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
    bfs(1);
    return 0;
}
/*
5
0 1
0 2
1 2
1 3
2 4
*/