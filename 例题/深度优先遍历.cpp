#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int size = 100;
int graph[size][size];
int v,e;
int book[size];
void dfs(int cur)//cur是当前所在的顶点编号 
{
    int i;

    book[cur] = 1;
    int sum = 0;
    cout <<cur<<endl;
    sum++;  //每访问一个顶点sum就加1 
    book[cur]= 1;
    if (sum==v) 
        return;  // 所有的顶点都已经访问过则直接退出 
    for(i=1 ;i <= v; i++)  
    {
        //判断当前顶点cur到顶点i是否有边，并判断顶点i是否已访问过
        if(graph[cur][i]==1 && book[i]==0)
        {
            book[i]=1;  //标记顶点i已经访问过 
            dfs(i);  //从顶点i再出发继续遍历 
         } 
    }
    return;
 } 
 
 
int main()
{
    int v1,v2;
    cout << "请输入顶点数和边数"<<endl;
    cin >> v >> e;
    memset(graph,-1,sizeof(graph));
    memset(book,0,sizeof(book));
    cout <<"请输入边的前驱后驱"<<endl;    
    //读入顶点之间的边         
    for(int i=1;i<=e;i++)
    {
        cin >>v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = 1;  
    }     
    //从1号顶点出发
    dfs(1);  //从1号顶点开始遍历 

    return 0; 
}

/*
6 8
1 2
1 3
1 4
6 4
6 5
4 5
3 2
3 5
*/