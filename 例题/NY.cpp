#include <iostream>
#include <math.h>
using namespace std;

const int product = 707829217;
int a[product/2];

bool prime (int n)
{
    if (n == 1 || n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false; 
    }
    return true;
}

int main()
{
    int m = product/2;

    for (int i = 2,j = 0; i < m; i++,j++)
    {
        if (prime(i))
        {
            cout << i << endl;
            a[j] = i;
            cout << j<<endl;
        }
    }
    return 0;
}