#include <iostream>
#include <math.h>
using namespace std;


int factorial (int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
    {
        return n*factorial(n-1);
    }
    
}

int main()
{
    int n = factorial (100);
    int m = pow(2,50);
    cout << n;
    cout << n/m<<endl;
    return 0;
}