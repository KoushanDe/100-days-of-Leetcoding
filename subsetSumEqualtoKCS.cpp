#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
bool func(int i, int k, vector<int> &arr,vector<vector<int>>& dp)
{
    if(k==0)return true;
    if(i==0)return arr[0]==k;
    if(k<0)return false;
    if(dp[i][k]!=-1)return dp[i][k];
    return dp[i][k] = func(i-1,k,arr,dp)||func(i-1,k-arr[i],arr,dp)?1:0;
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1)); 
    return func(n-1,k,arr,dp);
}*/

/**TABULATION**/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0;i<n;i++)dp[i][0]=true;
    dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {    
            if(j-arr[i]>=0)
            dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i]];
            else
               dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[n-1][k];
}
