#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
 * int mod = (int)(1e9+7);
int func(vector<int>& num, int index, int tar,vector<vector<int>>& dp)
{
    if(index==0) //as arr element can be 0 hence this modified base case
    {
        if(tar==0&&num[0]==0) return 2; //tar=0 and index 0 elem is 0.. take or non take tar stays same
        if(tar==0) return 1; //if tar=0 but index 0 elem is 5 then if take tar -5: not possible, hence only not take
        if(tar==num[0])return 1; //this was the original base case
        return 0;
    }
    if(dp[index][tar]!=-1) return dp[index][tar];
    
    int notake = func(num,index-1,tar,dp);
    int take = 0;
    if(tar-num[index]>=0)
        take = func(num,index-1,tar-num[index],dp);
    
    return dp[index][tar]=(take+notake)%mod;
}
int countPartitions(int n, int d, vector<int> &num) {
    //s1+s2=sum
    //s1-s2=D
    //2s2=sum-D
    //s2=(sum-D)/2
    //sum should be >= D, sum-D should be even
    int sum=0;
    for(auto elem:num)
        sum+=elem;
    if(sum<d)return 0;
    if((sum-d)%2!=0)return 0;
    int tar = (sum-d)/2;
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    
    return func(num,n-1,tar,dp)%mod;
}
*/

/**TABULATION**/
int mod = (int)(1e9+7);

int countPartitions(int n, int d, vector<int> &num) {
    //s1+s2=sum
    //s1-s2=D
    //2s2=sum-D
    //s2=(sum-D)/2
    //sum should be >= D, sum-D should be even
    int sum=0;
    for(auto elem:num)
        sum+=elem;
    if(sum<d)return 0;
    if((sum-d)%2!=0)return 0;
    int tar = (sum-d)/2;

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0]==0)dp[0][0] = 2;
    else dp[0][0] = 1;
    if(num[0]!=0&&num[0]<=tar)dp[0][num[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int notake = dp[i-1][j];
            int take = 0;
            if(j-num[i]>=0)
                take = dp[i-1][j-num[i]];
            dp[i][j] = (take+notake)%mod;
        }
    }
    return dp[n-1][tar];
}
