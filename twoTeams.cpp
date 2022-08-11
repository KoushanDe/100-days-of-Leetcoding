int dfs(vector<vector<int>>& graph,int node, int col,vector<int>& colour)
{
    colour[node]=col;
    
    for(int child:graph[node])
    {
        if(colour[child]==-1)
        {
            if(dfs(graph,child,!col,colour)==0)
            return 0;
        }
        else if(colour[child]==col)
        return 0;
    }
    
    return 1;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    
    for(int i=0;i<B.size();i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    
    vector<int> colour(A+1,-1);
    
    for(int i=1;i<=A;i++)
    {
        if(colour[i]==-1)
        {
            if(dfs(graph,i,0,colour)==0)
            return 0;
        }
    }
    
    return 1;
}
