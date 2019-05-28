#include <iostream>
#include <algorithm>
using namespace std;

void judge (int a, int b)
{
    if (a == b)
    {
        cout << a <<endl;
        return;
    }
    if ( a > b)
    {
        a /= 2;
        judge (a,b);
    }
    else if (a < b)
    {
        b /= 2;
        judge(a,b);
    }
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        judge(a,b);
    }
    return 0;
}