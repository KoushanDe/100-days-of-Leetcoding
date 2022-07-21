#include<bits/stdc++.h>

//using bfs
bool bfs(int root, vector<vector<int>>& graph, vector<int>& vis)
{
    queue<pair<int,int>> q;
    
    vis[root]=1;
    q.push({root,-1});
    
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto child:graph[node])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push({child,node});
            }
            else
            {
                if(child!=parent)
                    return true;
            }
        }
    }
    
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1);
    
    for(int i=0;i<m;i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> vis(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(bfs(i,graph,vis))
                return "Yes";
        }
    }
    
    return "No";
}

//Using DFS
#include<bits/stdc++.h>
bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int parent)
{
    vis[node]=1;
       
    for(auto child:graph[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,graph,vis,node))
                return true;
        }
        else if(child!=parent)
            return true;
    }
    
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1);
    
    for(int i=0;i<m;i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> vis(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i,graph,vis,-1))
                return "Yes";
        }
    }
    
    return "No";
}
