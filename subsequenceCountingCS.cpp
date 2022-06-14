#include<bits/stdc++.h>
using namespace std;
int mod = (int)(1e9+7);
/**MEMOISATION**
int func(string &t, string &s, int i, int j,vector<vector<int>>& dp)
{    
    if(j==0) return 1; //small string gets exhausted
    if(i==0) return 0; //big string gets exhausted but small string still remains
    if(dp[i][j]!=-1)return dp[i][j];
    if(t[i-1]==s[j-1])
        return dp[i][j]=(func(t,s,i-1,j-1,dp) + func(t,s,i-1,j,dp))%mod;
                //take                notake for further investigation
    else
        return dp[i][j]=func(t,s,i-1,j,dp)%mod;
}*/
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp(lt+1,vector<int>(ls+1,0));
    for(int i=0;i<=lt;i++)
        dp[i][0]=1;
    for(int j=1;j<=ls;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=lt;i++)
        for(int j=1;j<=ls;j++)
        {
            if(t[i-1]==s[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            else
                dp[i][j] = dp[i-1][j];
        }
    return dp[lt][ls];
}

/**SPACE OPTIMISED**
 * int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<int> prev(ls+1,0);
    vector<int> curr(ls+1,0);
    prev[0]=curr[0]=1;
    
    for(int i=1;i<=lt;i++)
    {
        for(int j=1;j<=ls;j++)
        {
            if(t[i-1]==s[j-1])
                curr[j] = (prev[j-1] + prev[j])%mod;
            else
                curr[j] = prev[j];
        }
        prev=curr;
    }
        
    return prev[ls];
}*/