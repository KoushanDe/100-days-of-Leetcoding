int dfs(vector<string>& grid,int x, int y,string& word, int ind)
{   
    if(ind==word.size())
    return 1;
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    
    for(int i=0;i<4;i++)
    {
        int newx = x+dx[i];
        int newy = y+dy[i];
        
        if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&grid[newx][newy]==word[ind])
        {
            if(dfs(grid,newx,newy,word,ind+1)==1)
            return 1;
        }
    }
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==B[0])
            {
                if(dfs(A,i,j,B,1)==1)
                return 1;
            }
        }
    }
    
    return 0;
}
