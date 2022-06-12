#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& profit,vector<int>& wt,int index, int W, vector<vector<int>>& dp)
{    
    if(index==0)
    return profit[0]*(W/wt[0]);
    if(dp[index][W]!=-1)return dp[index][W];
    
    int notake = func(profit,wt,index-1,W,dp);
    int take = 0;
    if(wt[index]<=W)
        take = profit[index]+func(profit,wt,index,W-wt[index],dp);
    
    return dp[index][W]=max(take,notake);
}*/
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{   
    //vector<vector<int>> dp(n,vector<int>(w+1,-1)); memoisation dp
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int j=0;j<=w;j++)
    {
        dp[0][j] = profit[0]*(j/weight[0]);
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int notake = dp[i-1][j];
            int take = 0;
            if(weight[i]<=j)
                take = profit[i]+dp[i][j-weight[i]];

            dp[i][j]=max(take,notake);
        }
    }
    return dp[n-1][w];
}
