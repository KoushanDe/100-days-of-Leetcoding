void dfs(vector<vector<int>>&matrix,int node,int parent,int count,int& ans,vector<int>& A,int C)
{
    if(A[node-1]==1)
    count++;
    
    for(auto child:matrix[node])
    {   
        if(child!=parent)
        dfs(matrix,child,node,count,ans,A,C);
        else if(matrix[node].size()==1&&count<=C)
        ans++;
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<vector<int>> matrix(n+1);
    
    for(int i=0;i<B.size();i++)
    {
        matrix[B[i][0]].push_back(B[i][1]);
        matrix[B[i][1]].push_back(B[i][0]);
    }
    
    int count=0;
    int ans=0;
    
    dfs(matrix,1,-1,0,ans,A,C);
    
    return ans;
}
