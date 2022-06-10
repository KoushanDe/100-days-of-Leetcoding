#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& num, int index, int tar,vector<vector<int>>& dp)
{
    if(tar==0) return 1;
    if(index==0)return num[0]==tar?1:0;
    if(dp[index][tar]!=-1) return dp[index][tar];
    
    int notake = func(num,index-1,tar,dp);
    int take = 0;
    if(tar-num[index]>=0)
        take = func(num,index-1,tar-num[index],dp);
    
    return dp[index][tar]=take+notake;
}
int findWays(vector<int> &num, int tar)
{    
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return func(num,n-1,tar,dp);
}*/

/**TABULATION**/
int findWays(vector<int> &num, int tar)
{    
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    if(tar>=num[0])dp[0][num[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int notake = dp[i-1][j];
            int take = 0;
            if(j-num[i]>=0)
                take = dp[i-1][j-num[i]];
            dp[i][j] = take+notake;
        }
    }
    return dp[n-1][tar];
}
