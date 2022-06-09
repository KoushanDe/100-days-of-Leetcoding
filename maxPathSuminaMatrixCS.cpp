/**MEMOISATION**/
#include<bits/stdc++.h>
int func(vector<vector<int>>& matrix,int i, int j,int n, int m,vector<vector<int>>& dp)
{
    if(i==n-1)return matrix[i][j];
    if(dp[i][j]!=INT_MIN) return dp[i][j];
    
    int down = func(matrix,i+1,j,n,m,dp);
    int dl = j==0? INT_MIN : func(matrix,i+1,j-1,n,m,dp);
    int dr = j==m-1? INT_MIN : func(matrix,i+1,j+1,n,m,dp);
    
    return dp[i][j]=matrix[i][j] + max(down,max(dl,dr));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{    
    int maxm = INT_MIN;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),INT_MIN));
    for(int j=0;j<matrix[0].size();j++)
    {
        maxm = max(maxm,func(matrix,0,j,matrix.size(),matrix[0].size(),dp));
    }
   return maxm;
}