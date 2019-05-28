#include <iostream>
#include <cstring>
using namespace std;

int a[100];
bool judge(int n)
{
    memset(a,0,sizeof(a));
    a[0] =n%10;
    int i = 0;
    while (n /= 10)
    {
        a[++i] = n%10;
    }
    int j = 0;
    while (j <= i)
    {
        if (a[j] != a[i])
            return false;
        j++;
        i--;
    }
    return true;
}
int main()
{
    int n = 0;
    for (int i = 0; i < 256; i++)
    {
        n = i*i;
        if (judge(n))
            cout <<i<<endl;
    }
    return 0;
}