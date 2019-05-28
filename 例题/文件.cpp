#include <algorithm>    //头文件
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{   
    freopen("Data.txt","r",stdin);// 按顺序读入（仅此一行）
    double ans = 0;
    double a,b;
    while(scanf("%lf%lf",&a,&b)!=EOF){
        cout<<a<<" "<<b<<endl;
    }

    return 0;        //最终的结果是：608.100000
}
