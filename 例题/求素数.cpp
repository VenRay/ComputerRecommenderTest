//素数
#include <iostream>
#include <math.h>

using namespace std;

int Inverse (int x) //反转
{
    return ((x%10)*10 + x/10);
}
bool Juage(int x) //求素数
{
    if (x == 1 || x == 0)
        return false;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int M,N;
    cin >> M>>N;
    int a[100000];
    int j = 0;
    for (int i = M; i<= N; i++)
    {
        if (Juage(i) && Juage(Inverse(i)))
        {
            a[j++] = i;
        }
    }
    for (int i = 0; i < j; i++)
    {
        if (i == j-1)
            cout<<a[i]<<endl;
        else
            cout<<a[i]<<",";
    }
}