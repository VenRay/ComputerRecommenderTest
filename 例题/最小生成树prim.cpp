//poj-1258 
#include <stdio.h> 
#include <string.h> 
#include <iostream>
using namespace std;

#define MaxInt 0x3f3f3f3f 
//赋最大值
#define N 110 
//创建map二维数组储存图表，low数组记录每2个点间最小权值，visited数组标记某点是否已访问 
//成环必须开始最终同一个点，利用visit可避免成环。
int map[N][N],low[N],visited[N]; 
int n;   
int prim() 
{ 
    int i,j,pos,min,result=0; 
    memset(visited,0,sizeof(visited)); 
    visited[1]=1;pos=1; //从某点开始，分别标记和记录该点 

    for(i=1;i<=n;i++)   //第一次给low数组赋值 
    {
 //       if(i!=pos) 
            low[i]=map[pos][i]; 
    }
    for(i=1;i<n;i++)    //再运行n-1次 
    {         
        min=MaxInt; //找出最小权值并记录位置 
        for(j=1;j<=n;j++) 
            if(visited[j]==0&&min>low[j]) 
            { 
                min=low[j];
                pos=j; 
                cout <<"pos"<<endl;
            } 
        result+=min;    //最小权值累加
        cout << min << endl; 
        visited[pos]=1;     //标记该点 
        for(j=1;j<=n;j++)   //更新权值 
            if(visited[j]==0&&low[j]>map[pos][j]) //若当前节点之间距离小于当前距离，更新
                low[j]=map[pos][j]; 
    } 
    return result; 
} 
  
int main() 
{ 
    int i,v,j,ans; 
    while(scanf("%d",&n)!=EOF) 
    { 
        memset(map,MaxInt,sizeof(map)); //所有权值初始化为最大 
        for(i=1;i<=n;i++) 
            for(j=1;j<=n;j++) 
            { 
                scanf("%d",&v); 
                map[i][j]=map[i][j]=v; 
            } 
            ans=prim(); 
            printf("%d\n",ans); 
    } 
    return 0; 
}

/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

*/