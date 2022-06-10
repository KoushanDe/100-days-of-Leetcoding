#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
bool func(vector<int>& arr,int index,int target,vector<vector<int>>& dp)
{
    if(target==0)return true;
    if(index==0)return arr[0]==target;
    if(dp[index][target]!=-1)return dp[index][target];
    bool notake = func(arr,index-1,target,dp);
    bool take = false;
    
    if(target-arr[index]>=0)
        take = func(arr,index-1,target-arr[index],dp);
    
    return dp[index][target]=take|notake;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];   
    int s1 = sum/2;
    
    vector<vector<int>> dp(n,vector<int>(s1+1,-1));
    
    for(int i=s1;i>=0;i--)
    {
        if(func(arr,n-1,i,dp)==true)
            return abs(sum-2*i);
    }
    return 0;
}*/

/**TABULATION**/
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];   
    int s1 = sum/2;
    
    vector<vector<bool>> dp(n,vector<bool>(s1+1,false));
    
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=s1;j++)
        {
            bool notake = dp[i-1][j];
            bool take = false;
            
            if(j-arr[i]>=0)
                take = dp[i-1][j-arr[i]];
            
            dp[i][j] = take|notake;
        }
    }
    for(int i=s1;i>=0;i--)
    {
        if(dp[n-1][i]==true)
            return abs(sum-2*i);
    }
    return 0;
}

