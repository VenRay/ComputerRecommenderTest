//欧几里德算法（辗转相除法）求最大公约数
#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b,a%b);
    
}
int main()
{
    int a,b;
    cout<<"请输入两个数以求最大公约数"<<endl;
    cin>>a>>b;
    cout << gcd(a,b)<<endl;
    return 0;
}
