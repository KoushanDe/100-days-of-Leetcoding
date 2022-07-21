#include<bits/stdc++.h>
void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, stack<int>& st)
{
    vis[node] = 1;
    
    for(auto child:graph[node])
    {
        if(vis[child]==0)
        {
            dfs(child,graph,vis,st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> graph(v);
    
    for(int i=0;i<e;i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        graph[a].push_back(b);
    }
    
    vector<int> toposort;
    stack<int> st;
    vector<int> vis(v,0);
    
    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
            dfs(i,graph,vis,st);
    }
    
    while(!st.empty())
    {
        toposort.push_back(st.top());
        st.pop();
    }
    
    return toposort;
}