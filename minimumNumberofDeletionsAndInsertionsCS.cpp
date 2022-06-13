#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{    
    int n = s.size();
    int m = t.size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i]==t[j])
                dp[i][j]=1 + (i==0||j==0?0:dp[i-1][j-1]);
            else
                dp[i][j]=0 + max((i==0?0:dp[i-1][j]),(j==0?0:dp[i][j-1]));
        }
    }
    return dp[n-1][m-1];
}
int canYouMake(string &str, string &ptr)
{
    int len = lcs(str,ptr);
    return str.size()+ptr.size()-2*len;
}