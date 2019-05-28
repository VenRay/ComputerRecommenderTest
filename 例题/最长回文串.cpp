#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;
int dp[maxn][maxn];

int main()
{
    string s;
    cin >> s;
    memset(dp,0,sizeof(dp));
    int len = s.length();
    for (int i = len-1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i+1; j< len; j++)
        {
            if (s[i] == s[j]) //最长回文串不一定连续哦
                dp[i][j] = dp[i+1][j-1]+2;
            else
            {
                dp[i][j]= max(dp[i+1][j],dp[i][j-1]);
            }    
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    cout <<"最长回文串字符个数为:"<<dp[0][len-1]<<endl;
    return 0;
}
//dadccd