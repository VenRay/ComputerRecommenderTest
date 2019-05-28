/*
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？ 
6
45 12 45 32 5 6
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        int *p=new int[N];
        for(int i=0;i<N;i++)
        {
            cin>>p[i];
        }
        sort(p,p+N);
        //求取差最小的对数，肯定是相邻相减得到
        int Max=p[1]-p[0],Min=p[1]-p[0];
        int maxnumber=0,minnumber=0;
        for(int i=1;i<N;i++)
        {
             if((p[i]-p[i-1])<Min)
                    Min=p[i]-p[i-1];
        }
        if(Min==0){
                for(int i=0;i<N-1;i++)
                {
                    for(int j=i+1;j<N;j++)
                        if(p[i]==p[j])
                        minnumber++;
                }
 
        }else{
            for(int i=1;i<N;i++)
            {
             if((p[i]-p[i-1])==Min)
                    minnumber++;
            }
        }
        //求取差最大的对数，，最大值数乘以最小值数
        Max=p[N-1]-p[0];
        int a=0,b=0;
        for(int i=0;i<N;i++)
        {
            if(p[i]==p[0])
                a++;
            if(p[i]==p[N-1])
                b++;
        }
        if(Max==0)
            maxnumber=N*(N-1)/2;
        else
            maxnumber=a*b;
        cout<<minnumber<<' '<<maxnumber<<endl;
        delete[] p;
    }
}