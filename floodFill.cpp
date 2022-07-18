class Solution {
public:
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};
    bool isValid(vector<vector<int>>& image, int i, int j, int startcol)
    {   
        int m = image.size();
        int n = image[0].size();
        
        if(i>=0&&i<m&&j>=0&&j<n&&image[i][j]==startcol)
            return true;
        
        return false;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int startcol, int color)
    {
        image[i][j] = color;
        
        for(int k=0;k<4;k++)
        {
            if(isValid(image,i+di[k],j+dj[k],startcol))
                dfs(image,i+di[k],j+dj[k],startcol,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcol=image[sr][sc];
        
        if(startcol==color)return image;
        
        dfs(image,sr,sc,startcol,color);
        
        
        return image;
    }
};