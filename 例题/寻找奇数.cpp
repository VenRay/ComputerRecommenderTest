#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000000;
int a[INF];
int b[INF];

int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        b[x]++;
    }
    for (int i = 0; i < INF; i++)
    {
        if (b[i]%2)
            cout << i <<endl;
    }
    return 0;
}