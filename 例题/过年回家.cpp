#include <iostream>

using namespace std;


const int INF = 100;
const int maxNum = 40;
int G[maxNum][maxNum];
int m , n;

void Dijskra(int f, int t)
{
    int dis[maxNum];
    int visited[maxNum];
    int min;
    int pos;

    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        dis[i] = G[f][i];
    }
    for (int i = 0; i <= n; i++)
    {
        min = INF;
        for (int j = 0; j <= n; j++)
        {
            if (!visited[j] && min > dis[j])
            {
                pos = j;
                min = dis[j];
            }
        }
        visited[pos] = 1;
        for (int j = 0; j <= n; j++)
        {
            if (!visited[j] && dis[j] > dis[pos] + G[pos][j])
            {
                dis[j] = dis[pos] + G[pos][j];
            }
        }
    }
    cout << dis[t]<<endl;
}

int main()
{
    int f,t,c;
    while (cin >> m >> n)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                G[i][j] = INF;
        for (int i = 0; i < m; i++)
        {
            cin >> f >> t >> c;
            G[f][t] = G[t][f] = c; 
        }
        Dijskra(0,n);
    }
    return 0;
}

/*
8 4
0 1 10
0 2 5
1 2 2
1 3 1
2 1 3
2 3 9
2 4 2
3 4 4
*/