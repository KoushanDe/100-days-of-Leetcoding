class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int ans=0;
        int n = grid.size();
        for(int j=0;j<n;j++)
        {   
            vector<int> temp;
            
            for(int i=0;i<n;i++)
            {
                temp.push_back(grid[i][j]);
            }
            for(int i=0;i<n;i++)
            {
                if(temp==grid[i])
                    ans++;
            }
        }
        
        return ans;
    }
};