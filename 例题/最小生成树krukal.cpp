#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;
typedef struct IN
{
    int a;
    int b;
    int c;
}IN;
IN s[5000];
int N,M;
int pre[110];
int cmp(IN a,IN b)
{
    return a.c < b.c ? 1:0;
}
int find(int x)
{
    int i,r,t;
    r=x;
    while(r!=pre[r])
        r=pre[r];
    while(x!=r) //依次上移，路径压缩.
    {
        i=pre[x];
        pre[x]=r;
        x=i;
    }
    return r;
}
int kruskal()
{
    int i,j,pa,pb,num=0,sum=0;
    for(i=0;i<=M;i++)
        pre[i]=i;
    for(i=0;i<N;i++)
    {
        pa=find(s[i].a);
        pb=find(s[i].b);
        if(pa!=pb)
        {
            pre[pa]=pb;
            sum+=s[i].c;
            num++;
        }
    }
    if(num==M-1)
        return sum;
    else
        return 0;
}
int main()
{
    while(scanf("%d %d",&N,&M),N)
    {
        int i,j,t;
        memset(s,0,sizeof(s));
        for(i=0;i<N;i++)
        scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
        sort(s,s+N,cmp);
        //for(i=0;i<N;i++)
        //printf("%d\n",s[i].c);
        t=kruskal();
        if(t)
        printf("%d\n",t);
        else
        printf("?\n");
    }
    return 0;
}
/*
3 3
1 2 1
1 3 2
2 3 4
*/