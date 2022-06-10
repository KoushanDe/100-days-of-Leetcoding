#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
bool canPartition(vector<int> &arr, int n)
{    
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];   
    if(sum%2!=0)return false;
    sum/=2;
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool notake = dp[i-1][j];
            bool take = false;
            
            if(j-arr[i]>=0)
                take = dp[i-1][j-arr[i]];
            
            dp[i][j] = take|notake;
        }
    }
    
    return dp[n-1][sum];
}*/

/**TABULATION**/
bool canPartition(vector<int> &arr, int n)
{    
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];   
    if(sum%2!=0)return false;
    sum/=2;
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool notake = dp[i-1][j];
            bool take = false;
            
            if(j-arr[i]>=0)
                take = dp[i-1][j-arr[i]];
            
            dp[i][j] = take|notake;
        }
    }
    
    return dp[n-1][sum];
}
