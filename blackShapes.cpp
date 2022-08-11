int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void dfs(vector<string>& matrix, int i, int j, vector<vector<int>>& vis)
{
    vis[i][j]=1;
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int d=0;d<4;d++)
    {
        int newi=i+di[d];
        int newj=j+dj[d];
        if(newi>=0&&newi<n&&newj>=0&&newj<m&&matrix[newi][newj]=='X'&&vis[newi][newj]==0)
        dfs(matrix,newi,newj,vis);
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    int cc=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='X'&&vis[i][j]==0)
            {
                dfs(A,i,j,vis);
                cc++;
            }
        }
    }
    
    return cc;
}
