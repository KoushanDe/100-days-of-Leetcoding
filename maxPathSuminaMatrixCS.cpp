/**MEMOISATION**
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
*/
/**TABULATION**/
#include<bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{    
    int maxm = INT_MIN;
    int n = matrix.size(),m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i==n-1)dp[i][j] = matrix[i][j];
            else
            {    
                int down = dp[i+1][j];
                int dl = j==0? INT_MIN : dp[i+1][j-1];
                int dr = j==m-1? INT_MIN : dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + max(down,max(dl,dr));
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        maxm = max(maxm,dp[0][j]);
    }
   return maxm;
}