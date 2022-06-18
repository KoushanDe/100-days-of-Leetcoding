#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int f(vector<int>& a,int i, int j,vector<vector<int>>& dp)
{
    if(i>j) return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    int maxm=INT_MIN;
    for(int ind=i;ind<=j;ind++)
    {
        int coins = a[i-1]*a[ind]*a[j+1] + f(a,i,ind-1,dp)+f(a,ind+1,j,dp);
        if(coins>maxm) maxm=coins;
    }
    return dp[i][j]=maxm;
}*/

int maxCoins(vector<int>& a)
{    
    int n = a.size();
    a.insert(a.begin(),1);
    a.push_back(1);
    //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            int maxm=INT_MIN;
            for(int ind=i;ind<=j;ind++)
            {
                int coins = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1]+dp[ind+1][j];
                if(coins>maxm) maxm=coins;
            }
            dp[i][j]=maxm;
        }
    }
	return dp[1][n];
}