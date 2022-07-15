class Solution {
public:
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};
    
    bool isValid(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0||i>=m||j<0||j>=n||vis[i][j]!=0||grid[i][j]==0)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int& area)
    {
        vis[i][j] = 1;
        area++;
        
        for(int d=0;d<4;d++)
        {
            if(isValid(grid,vis,i+di[d],j+dj[d]))
                dfs(grid,vis,i+di[d],j+dj[d],area);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0)); //vis can be removed if we are allowed to make changes in given array ie, when a 1 is visited make it 0
        int maxarea = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(vis[i][j]==0&&grid[i][j]==1)
                {
                    int area=0;
                    dfs(grid,vis,i,j,area);
                    maxarea=max(area,maxarea);
                }
            }
        }
        
        return maxarea;
    }
};