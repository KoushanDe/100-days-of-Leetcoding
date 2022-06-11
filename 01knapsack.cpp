#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& wt, vector<int>& val, int index, int W, vector<vector<int>>& dp)
{
    if(index<0) return 0;
    if(W==0) return 0;
    
    if(dp[index][W]!=-1)return dp[index][W];
    int notake = func(wt,val,index-1,W,dp);
    int take = 0;
    if(wt[index]<=W) take = val[index] + func(wt,val,index-1,W-wt[index],dp);
    
    return dp[index][W]=max(take,notake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return func(weight,value,n-1,maxWeight,dp);
}*/

/**TABULATION**/
int func(vector<int>& wt, vector<int>& val, int index, int W, vector<vector<int>>& dp)
{
    if(index<0) return 0;
    if(W==0) return 0;
    
    if(dp[index][W]!=-1)return dp[index][W];
    int notake = func(wt,val,index-1,W,dp);
    int take = 0;
    if(wt[index]<=W) take = val[index] + func(wt,val,index-1,W-wt[index],dp);
    
    return dp[index][W]=max(take,notake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{    
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int i=0;i<n;i++)
        for(int j=1;j<=maxWeight;j++)
        {
            int notake = 0;
            int take = 0;
            if(i>0) notake = dp[i-1][j];
            if(j>=weight[i])
            {
                take = value[i];
                if(i>0) take+=dp[i-1][j-weight[i]];
            }
            dp[i][j] = max(take,notake);
        }
	return dp[n-1][maxWeight];
}