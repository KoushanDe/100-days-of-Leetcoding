#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int f(vector<int>& cuts,int i, int j,vector<vector<int>>& dp)
{
    if(i>j) return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    int minm = INT_MAX;
    for(int k=i;k<=j;k++)
    {    
        int cost = cuts[j+1]-cuts[i-1] + f(cuts,i,k-1,dp) + f(cuts,k+1,j,dp);
        if(cost<minm)minm=cost;
    }
    return dp[i][j]=minm;
}*/
/**TABULATION**/
int cost(int n, int c, vector<int> &cuts){
    sort(cuts.begin(),cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c;i>=1;i--)
    {
        for(int j=i;j<=c;j++)
        {
            int minm = INT_MAX;
            for(int k=i;k<=j;k++)
            {    
                int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                if(cost<minm)minm=cost;
            }
            dp[i][j]=minm;
        }
    }
    return dp[1][c];
}