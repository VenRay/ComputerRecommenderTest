    #include<iostream>
    using namespace std;
     
    int  pre[1050];
    bool t[1050];               //t 用于标记独立块的根结点
     
    int Find(int x)
    {
    	int r=x;
    	while(r!=pre[r])
    		r=pre[r];
    	
    	int i=x,j;
        //路径压缩
    	while(pre[i]!=r)
    	{
    		j=pre[i];
    		pre[i]=r;
    		i=j;
    	}
    	return r;
    }
     
    void mix(int x,int y)
    {
    	int fx=Find(x),fy=Find(y);
    	if(fx!=fy)
    	{
    		pre[fy]=fx;
    	}
    } 
     
    int main()
    {
    	int N,M,a,b,i,j,ans;
    	while(scanf("%d%d",&N,&M)&&N)
    	{
    		for(i=1;i<=N;i++)          //初始化 
    			pre[i]=i;
    		
    		for(i=1;i<=M;i++)          //吸收并整理数据 
    		{
    			scanf("%d%d",&a,&b);
    			mix(a,b);
    		}
    		
    		
    		memset(t,0,sizeof(t));
    		for(i=1;i<=N;i++)          //标记根结点
    		{
    			t[Find(i)]=1;
    		}
    		for(ans=0,i=1;i<=N;i++)
    			if(t[i])
    				ans++;
    				
    		printf("%d\n",ans-1);
    		
    	}
    	return 0;
    }//dellaserss