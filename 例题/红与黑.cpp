#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 22
using namespace std;
 
int w,h;
char tile[N][N];
int ans;
 
void bfs(int row,int column)
{
    if(row<0||column<0||row>h||column>w)
        return ;
    else
    {
        ans++;
        if(tile[row+1][column]=='.')
        {
            tile[row+1][column]='#';
            bfs(row+1,column);
        }
        if(tile[row-1][column]=='.')
        {
            tile[row-1][column]='#';
            bfs(row-1,column);
        }
        if(tile[row][column+1]=='.')
        {
            tile[row][column+1]='#';
            bfs(row,column+1);
        }
        if(tile[row][column-1]=='.')
        {
            tile[row][column-1]='#';
            bfs(row,column-1);
        }
    }
}
 
int main()
{
    scanf("%d%d",&w,&h);
    int row,column;
    while(w!=0&&h!=0)
    {
        ans=0;
        for(int i=0;i<h;i++)
        scanf("%s",tile[i]);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                if(tile[i][j]=='@')
                {
                    row=i;
                    column=j;
                    tile[i][j]='#';
                }
            }
        bfs(row,column);
        printf("%d\n",ans);
        memset(tile,0,sizeof(tile));
        scanf("%d%d",&w,&h);
    }
 
    return 0;
}