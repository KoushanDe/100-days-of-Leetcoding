#include<bits/stdc++.h>
using namespace std;
/**Memoisation**
int func(string s, string t, int inds, int indt,vector<vector<int>>& dp)
{    
    if(inds<0||indt<0) return 0;
    if(dp[inds][indt]!=-1)return dp[inds][indt];
    if(s[inds]==t[indt])
        return dp[inds][indt]=1 + func(s,t,inds-1,indt-1,dp);
    else
        return dp[inds][indt]=0 + max(func(s,t,inds-1,indt,dp),func(s,t,inds,indt-1,dp));
}*/
int lcs(string s, string t)
{    
    int n = s.size();
    int m = t.size();
    //vector<vector<int>> dp(n,vector<int>(m,-1)); memoisation dp
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