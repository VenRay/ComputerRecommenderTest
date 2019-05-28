#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 105;
char str[N];
int dp[N][N];
 
int main(){
    while(~scanf("%s",str))  {
        memset(dp,0,sizeof(dp));
        int len = strlen(str);
        for(int i = len - 1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < len; j++)
                if(str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
        printf("%d\n",dp[0][len-1]);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                cout << dp[i][j]<<" ";
            }
            cout << endl;
        }
    }
    return 0;
}