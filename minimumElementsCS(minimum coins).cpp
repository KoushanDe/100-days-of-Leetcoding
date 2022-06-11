#include<bits/stdc++.h>
using namespace std;
/**TABULATION**/
int minimumElements(vector<int> &num, int x)
{    
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,1e9));
    for(int j=0;j<=x;j++)
    {
        if(j%num[0]==0) dp[0][j]=j/num[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            int notake = dp[i-1][j];
            int take = 1e9;
            if(j>=num[i])
                take = 1 + dp[i][j-num[i]];
            dp[i][j] = min(take,notake);
        }
    }
    int ans = dp[n-1][x];
    return ans>=1e9?-1:ans;
}

/**MEMOISATION**
int func(vector<int>& num, int index, int target,vector<vector<int>>& dp)
{    
    if(index==0)
    {
        if(target%num[0]==0) return target/num[0];
        else return 1e9;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    
    int notake = func(num,index-1,target,dp);
    int take = 1e9;
    if(target>=num[index])
        take = 1 + func(num,index,target-num[index],dp);
    
    return dp[index][target]=min(notake,take);
}*/