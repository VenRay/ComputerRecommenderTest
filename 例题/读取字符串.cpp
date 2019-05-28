#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char s[10];
    char b[10];
    //char c = getchar();
    cin >> s;
    cin >> b;
    cout << s<<endl;
    cout << strcmp(s,b);
    if (!strcmp(s, b)) 
        cout << '1'<<endl;
    return 0;
}