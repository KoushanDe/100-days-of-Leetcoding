class Solution {
public:
    int mod = (int)(1e9+7);
    
    
    int f(int i, int j, int m, int n, int movesleft,vector<vector<vector<int>>>& dp)
    {
        if(i<0||i>=m||j<0||j>=n)
            return 1;
        if(movesleft==0)
            return 0;
        
        if(dp[i][j][movesleft]!=-1) return dp[i][j][movesleft];
        
        long long up = f(i-1,j,m,n,movesleft-1,dp);
        long long down = f(i+1,j,m,n,movesleft-1,dp);
        long long left = f(i,j-1,m,n,movesleft-1,dp);
        long long right = f(i,j+1,m,n,movesleft-1,dp);
        
        return dp[i][j][movesleft] = (up+down+left+right)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       if(maxMove==0) return 0;
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(startRow,startColumn,m,n,maxMove,dp);
    }
};