class Solution {
public:
    void dfs(vector<vector<int>>& adjlist, int node, vector<int>& vis, vector<int>& dfsvis, int& cyclelen, int& dist)
    {
        vis[node]=1;
        dfsvis[node]=dist;
        dist++;
        
        for(int child:adjlist[node])
        {
            if(vis[child]==0)
                dfs(adjlist,child,vis,dfsvis,cyclelen,dist);
            else if(dfsvis[child]!=-1)
            {
                cyclelen = max(cyclelen,dfsvis[node]-dfsvis[child]+1);
            }
        }
        dfsvis[node]=-1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adjlist(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                adjlist[i].push_back(edges[i]);
        }
        
        vector<int> vis(n,0),dfsvis(n,-1);
        int longestCycle = -1;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {   
                int cyclelen = -1;
                int dist = 0;
                dfs(adjlist,i,vis,dfsvis,cyclelen,dist);
                if(cyclelen>longestCycle)
                    longestCycle=cyclelen;
            }
        }
        
        return longestCycle;
    }
};