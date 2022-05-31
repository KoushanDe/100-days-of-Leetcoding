#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int lipdfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i, int j,int prev)
    {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()||matrix[i][j]<=prev)return 0;
        
        if(dp[i][j]>0)return dp[i][j];
        
        int up = lipdfs(matrix,dp,i-1,j,matrix[i][j]);
        int down = lipdfs(matrix,dp,i+1,j,matrix[i][j]);
        int left = lipdfs(matrix,dp,i,j-1,matrix[i][j]);
        int right = lipdfs(matrix,dp,i,j+1,matrix[i][j]);
        
        return dp[i][j] = max(max(max(up,down),left),right)+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())return 0;
        int m = matrix.size(),n=matrix[0].size();
        
        vector<vector<int>> dp (m,vector<int>(n,0));
        int longestPath=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int pathlength = lipdfs(matrix,dp,i,j,-1);
                longestPath=max(longestPath,pathlength);
            }
        }
        return longestPath;
    }
};