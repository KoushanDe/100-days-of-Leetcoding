#include<bits/stdc++.h>
using namespace std;
int MOD = (int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {    
            if(mat[i][j]==-1)dp[i][j]=0;
            else if(i==0&&j==0)dp[i][j]=1;
            else
            {    
                int up = i==0?0:dp[i-1][j];
                int left = j==0?0:dp[i][j-1];
                dp[i][j] = (up+left)%MOD;
            }
        }
    }
    return dp[n-1][m-1];
}