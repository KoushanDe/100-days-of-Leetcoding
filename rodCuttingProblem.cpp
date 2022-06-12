#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& price, int index, int rodlen,vector<vector<int>>& dp)
{    
    int cutlen=index+1;
    if(cutlen==1)
        return price[0]*(rodlen/cutlen); //basically price[0]*rodlen/1
    if(dp[index][rodlen]!=-1)return dp[index][rodlen];
    int nocut = func(price,index-1,rodlen,dp);
    int cut = 0;
    if(cutlen<=rodlen)
        cut = price[index] + func(price,index,rodlen-cutlen,dp);
    
    return dp[index][rodlen] = max(cut,nocut);
}*/
int cutRod(vector<int> &price, int n)
{    
    //vector<vector<int>> dp(n,vector<int>(n+1,-1)); **Memoisation dp**
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int j=0;j<=n;j++)
        dp[0][j] = price[0]*j;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {    
            int nocut = dp[i-1][j];
            int cut = 0;
    if(i+1<=j)
        cut = price[i] + dp[i][j-(i+1)];
    
    dp[i][j] = max(cut,nocut);
        }
    }
	return dp[n-1][n];
    //return func(price,n-1,n,dp);
}
