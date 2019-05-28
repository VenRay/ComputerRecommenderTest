#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int DP[1010][1010];
string s;

int main()
{
    while (cin >> s)
    {
        memset(DP,0,sizeof(DP));
        int len = s.length();
        for (int i = len - 1; i>= 0; i--)
        {
            DP[i][i] = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                    DP[i][j] = DP[i+1][j-1] + 2;
                else
                {
                    DP[i][j] = max(DP[i+1][j],DP[i][j-1]);
                }
                
            }
        }
        cout << len - DP[0][len-1]<<endl;
    }
    return 0;
}