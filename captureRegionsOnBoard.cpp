int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void dfs(vector<vector<char>>& matrix,int i,int j,vector<vector<int>>& vis)
{
    vis[i][j]=1;
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int d=0;d<4;d++)
    {   
        int newi=i+di[d];
        int newj=j+dj[d];
        if(newi>=0&&newi<n&&newj>=0&&newj<m&&matrix[newi][newj]=='O'&&vis[newi][newj]==0)
        dfs(matrix,newi,newj,vis);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    if(n<=2||m<=2) return;
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int j=0;j<m;j++)
    {
        if(A[0][j]=='O'&&vis[0][j]==0)
        dfs(A,0,j,vis);

    }
    for(int j=0;j<m;j++)
    {
        if(A[n-1][j]=='O'&&vis[n-1][j]==0)
        dfs(A,n-1,j,vis);
    }
    for(int i=0;i<n;i++)
    {
        if(A[i][0]=='O'&&vis[i][0]==0)
        dfs(A,i,0,vis);
    }
    for(int i=0;i<n;i++)
    {
        if(A[i][m-1]=='O'&&vis[i][m-1]==0)
        dfs(A,i,m-1,vis);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O'&&vis[i][j]==0)
            A[i][j]='X';
        }
    }
}
