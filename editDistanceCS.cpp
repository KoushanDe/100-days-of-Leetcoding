#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(string &str1, string &str2, int i, int j,vector<vector<int>>& dp)
{    
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(str1[i-1]==str2[j-1])
        return dp[i][j]=0 + func(str1,str2,i-1,j-1,dp);
    else
    {
        int ins = 1+func(str1,str2,i,j-1,dp);
        int del = 1+func(str1,str2,i-1,j,dp);
        int rplc = 1+func(str1,str2,i-1,j-1,dp);
        return dp[i][j]=min(ins,min(del,rplc));
    }
}*/

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int j=0;j<=m;j++) dp[0][j] = j;
    for(int i=0;i<=n;i++) dp[i][0] = i;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int ins = 1+dp[i][j-1];
                int del = 1+dp[i-1][j];
                int rplc = 1+dp[i-1][j-1];
                dp[i][j]=min(ins,min(del,rplc));
            }
        }
    }
    return dp[n][m];
}

/**SPACE OPTIMISATION**
 * int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<int> prev(m+1,0),curr(m+1,0);
    
    for(int j=0;j<=m;j++) prev[j] = j;
    
    for(int i=1;i<=n;i++)
    {    
    curr[0] = i;
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                curr[j] = prev[j-1];
            else
            {
                int ins = 1+curr[j-1];
                int del = 1+prev[j];
                int rplc = 1+prev[j-1];
                curr[j]=min(ins,min(del,rplc));
            }
        }
        prev = curr;
    }
    return prev[m];
}
*/