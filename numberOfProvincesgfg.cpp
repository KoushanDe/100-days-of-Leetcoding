#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(vector<vector<int>>& list,vector<int>& vis,int node)
    {
        vis[node] = 1;
        
        for(int child:list[node])
        {
            if(vis[child]==0)
            dfs(list,vis,child);
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> list(V);
        vector<int> vis(V);
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(adj[i][j]==1&&i!=j)
                list[i].push_back(j);
            }
        }
        
        int provinces = 0;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(list,vis,i);
                provinces++;
            }
        }
        return provinces;
    }
};