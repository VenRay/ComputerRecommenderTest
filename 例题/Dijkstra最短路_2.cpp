#include<cstdio>
#include <iostream>
#include <cstring>
#define SIZE 110  

#define MaxInt 0x3f3f3f3f 
using namespace std;

 
int map[SIZE][SIZE];  //邻接矩阵存储 
int len[SIZE];  	//d[i]表示源点到i这个点的距离 
int visit[SIZE];  //节点是否被访问 
int n,m;  
 
int dijkstra(int from, int to){	//从源点到目标点 
	
    int i;  
    int result = 0;
    int min;

    for(i = 1 ; i <= n ; i ++){	//初始化 
        visit[i] = 0;	//一开始每个点都没被访问 
        len[i] = map[from][i];	//先假设源点到其他点的距离 
    }  
    int j;  
    visit[from] = 1;
    for(i = 1 ; i < n ; ++i){	//对除源点的每一个点进行最短计算 
        min = MaxInt;  //记录最小len[i] 
        int pos;  //记录小len[i] 的点 
  
        for(j = 1 ; j <= n ; ++j){	
            if(!visit[j] && min > len[j]){  
                pos = j;  
                cout <<"pos"<<pos<<endl;
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
        result += min;
        cout << min <<endl;
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径  
                len[j] = len[pos] + map[pos][j];	//更新j节点到源节点的最短路径	
            }  
        }  
    }
    int sum = 0;  
    for (int i = 1; i <= n; i++)
        sum += len[i];
    cout << sum <<endl;
    cout << result<<endl;
    return len[to];
}
  
/*
int main () {  
 
    int i,j;  
 //   cout<<"请输入节点和边数"<<endl;
 //   scanf("%d%d",&n,&m);	//输入数据
	n = 6;	//测试数据 
	m = 9;
 
    for(i = 1 ; i <= n ; ++i){	//设一开始每个点都不可达 
        for(j = 1 ; j <= n ; ++j){  
            map[i][j] = INF;  
        }  
    }  
	cout<<"一次输入结点名和边的权"<<endl;
	int a,b,c;	//输入数据 
    for(i = 1 ; i <= m ; ++i){  
        scanf("%d%d%d",&a,&b,&c);  
        map[a][b] = map[b][a] = c;  
    }  
  
    map[1][2] = 7;	//测试数据 
	map[1][3] = 9;
	map[1][6] = 14;
	map[2][3] = 10;
	map[2][4] = 15;
	map[3][6] = 2;
	map[5][6] = 9;
	map[4][5] = 6;
	map[3][4] = 11;

    int temp = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(map[i][j] == temp)
				map[i][j] = map[j][i];
            cout <<map[i][j]<<endl;
		}
	}
 
    int ans = dijkstra(1,2);  
 
    printf("%d",ans);  
 
    return 0;  
} 
*/
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
        ans=dijkstra(1,2); 
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