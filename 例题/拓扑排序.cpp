#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int G[maxn][maxn];
int degree[maxn];
bool visited[maxn];
int node,edge;

void TopoSort()
{
    int num = 0;
    while (num < node)
    {
        for (int i = 0; i < node; i++)
        {
            if (!visited[i] && !degree[i])
            {
                visited[i] = 1;
                num++;
                cout <<i<<endl;
                for (int j = 0; j< node; j++)
                {
                    if (G[i][j])
                    {
                        degree[j]--;
                    }
                }
                break;
            }
        }
    }
}

int main()
{
    int to,out;
    memset(G,0,sizeof(G));
    memset(degree,0,sizeof(degree));
    memset(visited,0,sizeof(visited));
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >>out >> to;
        G[out][to] = 1;
        degree[to]++;;
    }
    TopoSort();
    return 0;
}
/*
5
6
2 0
2 1
0 1
0 3
3 1
1 4
*/