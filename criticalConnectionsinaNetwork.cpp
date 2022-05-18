#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,vector<int>> adj;
    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
    {
        static int time = 0;   
        disc[u] = low[u] = time;
        time +=1;
        
        for(int v: adj[u])
        {
            if(disc[v]==-1) 
            {
                parent[v] = u;
                DFS(v,disc,low,parent,bridges);
                low[u] = min(low[u],low[v]);
                
                if(low[v] > disc[u])
                    bridges.push_back(vector<int>({u,v}));
            }
            else if(v!=parent[u])   
                low[u] = min(low[u],disc[v]);
        }
    }
    void findBridges_Tarjan(int V,vector<vector<int>>& bridges)
    {
        vector<int> disc(V,-1),low(V,-1),parent(V,-1);
  
        for(int i=0;i<V;++i)
            if(disc[i]==-1)
                DFS(i,disc,low,parent,bridges);
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();++i)  
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>> bridges; 
        findBridges_Tarjan(n,bridges); 
        return bridges;
    }
};