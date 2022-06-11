/**MEMOISATION**/
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
}