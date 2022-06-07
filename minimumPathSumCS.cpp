#include<bits/stdc++.h>

using namespace std;

/**MEMOISATION**/
/*
#include<bits/stdc++.h>
int func(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
{
    if(i==0&&j==0)return grid[0][0];
    else if(i<0||j<0) return INT_MAX;
    
    if(dp[i][j]!=0)return dp[i][j];
    
    int up = func(grid,i-1,j,dp);
    int left = func(grid,i,j-1,dp);
    
    return dp[i][j]=grid[i][j] + min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    return func(grid,n-1,m-1,dp);
}
*/

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0)dp[i][j]=grid[i][j];
            else
            {    
                int up = i==0?INT_MAX:dp[i-1][j];
                int left = j==0?INT_MAX:dp[i][j-1];
                dp[i][j] = grid[i][j] + min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

