#include <iostream>

using namespace std;

void hanno(int n, char from,char to,char mid)
{
    if (n == 1)
    {
        cout <<"第"<<n<<"个 "<< from <<"->" << to<<endl;
        return ;
    }
    hanno (n-1, from,mid,to);
    cout <<"第"<<n<<"个 "<< from <<"->" << to<<endl;
    hanno (n-1,mid,to,from);
}

int main()
{
    int n;
    cout<<"输入盘子数"<<endl;
    cin >> n;
    hanno(n,'A','B','C');
    return 0;
}