#include <iostream>

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
int combination (int n,int i)
{
    return factorial(n)/(factorial(i)*factorial(n-i));
}

int main()
{
    //int n = 866278171;
    int n = 8;
    int sum = 0;
    for (int i = 1; i <= 8; i++)
    {
        sum += i*combination(n,i);
    }

    cout << ++sum << endl;
    return 0;
}