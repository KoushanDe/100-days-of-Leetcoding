class Solution {
public:
    int mod = (int)(1e9+7);
    int findTPath(vector<vector<int>>& matrix,int i, int j,int m,int n,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int totalPath=1;
        
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j])
            totalPath = (totalPath + findTPath(matrix,i-1,j,m,n,dp))%mod;
        if(i+1<m&&matrix[i+1][j]>matrix[i][j])
            totalPath = (totalPath + findTPath(matrix,i+1,j,m,n,dp))%mod;
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j])
            totalPath = (totalPath + findTPath(matrix,i,j-1,m,n,dp))%mod;
        if(j+1<n&&matrix[i][j+1]>matrix[i][j])
            totalPath = (totalPath + findTPath(matrix,i,j+1,m,n,dp))%mod;
        
        return dp[i][j] = totalPath;
    }
    int countPaths(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp (m,vector<int>(n,-1));
        
        int totalPath = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int pathsize = findTPath(grid,i,j,m,n,dp);
                totalPath = (totalPath+pathsize)%mod;
            }
        }
        return totalPath;
    }
};