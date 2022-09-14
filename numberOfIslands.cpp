class Solution {
public:
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    
    bool isValid(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int m,int n)
    {   
        
        if(x<0||x>=m||y<0||y>=n||grid[x][y]=='0'||vis[x][y]==1)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>>& grid,int i, int j,vector<vector<int>>& vis,int m, int n)
    {
        vis[i][j]=1;
        
        for(int d=0;d<4;d++)
        {
            int newi=i+di[d];
            int newj=j+dj[d];
            
            if(isValid(newi,newj,grid,vis,m,n))
                dfs(grid,newi,newj,vis,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==0)
                {
                    dfs(grid,i,j,vis,m,n);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};