#include<bits/stdc++.h>
using namespace std;

/**MEMOISATION**
int func(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp)
{
    if(i==triangle.size()-1)return triangle[i][j];
    if(dp[i][j]!=0)return dp[i][j];
    int down = func(triangle,i+1,j,dp);
    int diag = func(triangle,i+1,j+1,dp);
    
    return dp[i][j]=triangle[i][j] + min(down,diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    return func(triangle,0,0,dp);
}
*/

/**TABULATION**/

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i = n-1;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==n-1) dp[i][j] = triangle[i][j];
            else
            {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
    }
    return dp[0][0];
}