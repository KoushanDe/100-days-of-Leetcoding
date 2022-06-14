#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
bool func(string &pattern, string &text, int i, int j,vector<vector<int>>& dp)
{    
    if(i==0&&j==0)return true;
    if(i==0&&j>0)return false;
    if(j==0&&i>0){
        for(int k=0;k<i;k++)
        {
            if(pattern[k]!='*')
                return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pattern[i-1]==text[j-1]||pattern[i-1]=='?')
        return dp[i][j]=func(pattern,text,i-1,j-1,dp);
    if(pattern[i-1]=='*')
        return dp[i][j]=func(pattern,text,i-1,j,dp)||func(pattern,text,i,j-1,dp);
    else return dp[i][j]=false;
}*/
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int j=1;j<=m;j++) dp[0][j] = false;
    for(int i=1;i<=n;i++)
    {
        if(pattern[i-1]=='*')
            dp[i][0]=true;
        else
            break;
    }

    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pattern[i-1]==text[j-1]||pattern[i-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(pattern[i-1]=='*')
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            else
                dp[i][j]=false;
        }
    }
    return dp[n][m];
}
