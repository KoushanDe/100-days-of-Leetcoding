#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
long func(int* coins,int index, int target,vector<vector<long>>& dp)
{    
    if(index==0)
    {
        if(target%coins[0]==0) return 1;
        return 0;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    
    long notake = func(coins,index-1,target,dp);
    long take = 0;
    if(target>=coins[index])
        take = func(coins,index,target-coins[index],dp);
    
    return dp[index][target]=take+notake;
}*/
long countWaysToMakeChange(int *denominations, int n, int value)
{    
    //MEMO DP: vector<vector<long>> dp(n,vector<long>(value+1,-1));
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int j=0;j<=value;j++)
    {
        if(j%denominations[0]==0) dp[0][j]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            long notake = dp[i-1][j];
            long take = 0;
            if(j>=denominations[i])
                take = dp[i][j-denominations[i]];

            dp[i][j]=take+notake;
        }
    }
    return dp[n-1][value];
}