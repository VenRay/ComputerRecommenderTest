#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
const int maxn = 100000;
int a[maxn];
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=2;i<=n;i++){               //i从2累乘到n
            int s,c=0;                      //c代表进位
            for(int j=0;j<maxn;j++){     //3000是长度，
                s=a[j]*i+c;                 //s 暂存为i乘结果的某一位
                a[j]=s%10;                  
                c=s/10;  
                             //判断要进多少位
            }
        }
        int ans=0;
        //输出
        for(int i=maxn;i>=0;i--){
            if(a[i]==0&&ans==0)continue;    //不输出前缀0
            else{
            ans=1;
            printf("%d",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}