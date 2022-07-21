#include<bits/stdc++.h>
void bfs(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& toposort)
{    
    queue<int> q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int node = q.front();
        toposort.push_back(node);
        q.pop();
        
        for(auto child:graph[node])
        {
            indegree[child]--;
            if(indegree[child]==0)
                q.push(child);
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> graph(v);
    vector<int> indegree(v,0);
    
    for(int i=0;i<e;i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    vector<int> toposort;
    
    bfs(graph,indegree,toposort);
    
    return toposort;
}