#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubsequence(string s)
{
    string r=s;
    reverse(r.begin(),r.end());
    int n = s.size();
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    //can be omitted
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=n;j++)dp[0][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==r[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int minInsertion(string &str)
{
    return str.size()-longestPalindromeSubsequence(str);
}