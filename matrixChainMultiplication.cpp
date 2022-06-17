#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int f(vector<int>& arr, int i, int j,vector<vector<int>>& dp)
{
    if(i==j)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    int minm = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + f(arr,i,k,dp) + f(arr,k+1,j,dp);
        minm = min(minm,steps);
    }
    return dp[i][j]=minm;
}*/

/**TABULATION**/
int matrixMultiplication(vector<int> &arr, int N)
{    
    //vector<vector<int>> dp(N,vector<int>(N,-1));
    vector<vector<int>> dp(N,vector<int>(N,0));
    
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i+1;j<=N-1;j++)
        {
            int minm = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                minm = min(minm,steps);
            }
            dp[i][j]=minm;
        }
    }
    return dp[1][N-1];
}