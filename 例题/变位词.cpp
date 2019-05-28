#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N;
    string s1,s2;
    int tmp[50];
    for (int i = 0; i < N; i++)
    {
        memset(tmp,0,sizeof(tmp));
        cin >> s1;
        cin >> s2;
        int len1 = s1.length();
        int len2 = s1.length();
        if (len1 != len2)
        {
            cout <<"No"<<endl;
            return 0;
        }
        for (int j = 0; j < len1; j++)
            tmp[s1[j]-'0'] = 1;
        for (int j =0; j < len2; j++)
            
 
    }
}