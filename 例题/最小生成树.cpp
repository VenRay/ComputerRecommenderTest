    #include <stdio.h>
    #include <stdlib.h>
    #include <algorithm>
    #include <iostream>
    using namespace std;
    #define MAX 1000
    #define MAXE MAX
    #define MAXV MAX
    typedef struct
    {
    	int beginvex1;                     //边的起始顶点
    	int endvex2;                      //边的终止顶点
    	int weight;                    //边的权值
    }Edge;
     
    void kruskal(Edge E[],int n,int e)
    { 
    		int i,j,m1,m2,sn1,sn2,k;
    		int vset[MAXV];
    		for(i=1;i<=n;i++) 			//初始化辅助数组
    		{
    			vset[i]=i;	
    		}		
      		k=1;        			//表示当前构造最小生成树的第k条边，初值为1
      		j=0;                   	//E中边的下标，初值为0
    		while(k < e)            //判断是否加入了最小生成树中
    		{
           		m1=E[j].beginvex1;
           		m2=E[j].endvex2;     //取一条边的两个邻接点
    			sn1=vset[m1];
    			sn2=vset[m2];       //分别得到两个顶点所属的集合编号
    			if(sn1 != sn2)     //判断是否有单源回路
    			{
    					printf("(v%d,v%d): %d\n",m1,m2,E[j].weight);
    					k++;                //生成边数增l
    					if(k>=n)  
    						break;
    					for(i=1;i<=n;i++) //两个集合统一编号
    					{
    						 if (vset[i]==sn2)  //集合编号为sn2的改为sn1，防止生成回路
    								 vset[i]=sn1;
    					}
             }
        	 j++;                  //扫描下一条边
     
       }
    }

    bool cmp (Edge a, Edge b)
    {
        return a.weight < b.weight ? 1:0;
    } 
    int main()
    {
     
    		Edge E[MAXE];
    		int nume,numn;
    		//这里我写死，下面可以自己输入
    		//printf("输入边数和顶数:\n");
    		//scanf("%d%d",&nume,&numn);
    		nume=10;
    		numn=6;
    	
    		
    		printf("请输入各边及对应的的权值(起始顶点 终止顶点 权值)\n");

            freopen("tree","r",stdin);
            int i = 0;
            while (scanf("%d%d%d",&E[i].beginvex1,&E[i].endvex2,&E[i].weight) != EOF)
            {
                i++;
            }
    		//for(int i=0;i<nume;i++)
    		//	 scanf("%d%d%d",&E[i].beginvex1,&E[i].endvex2,&E[i].weight);
    		sort (E,E+nume,cmp);
    		//在这里对输入的数据进行排序，达到假设的要求，即：假设数组E存放图G中的
    		//所有边，且边已按权值从小到大的顺序排列
            //需要块排
/*
            1 2 6
1 3 1 
1 4 5
2 3 5
2 5 3
1 2 6
3 4 5
3 5 6
3 6 4
4 6 2
*/
    		kruskal(E,numn,nume);
    		return 0;
    }
     


