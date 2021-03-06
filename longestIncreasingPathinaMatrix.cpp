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

//Another approach
class Solution {
public:
    int findLPath(vector<vector<int>>& matrix, int i, int j, int m, int n,vector<vector<int>>& dp)
    {   
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int longestPath=1;
        
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j])
            longestPath = max(longestPath,1+findLPath(matrix,i-1,j,m,n,dp));
        if(i+1<m&&matrix[i+1][j]>matrix[i][j])
            longestPath = max(longestPath,1+findLPath(matrix,i+1,j,m,n,dp));
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j])
            longestPath = max(longestPath,1+findLPath(matrix,i,j-1,m,n,dp));
        if(j+1<n&&matrix[i][j+1]>matrix[i][j])
            longestPath = max(longestPath,1+findLPath(matrix,i,j+1,m,n,dp));
        
        return dp[i][j]=longestPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int longestPath = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int pathsize = findLPath(matrix,i,j,m,n,dp);
                longestPath = max(longestPath,pathsize);
            }
        }
        
        return longestPath;
    }
};