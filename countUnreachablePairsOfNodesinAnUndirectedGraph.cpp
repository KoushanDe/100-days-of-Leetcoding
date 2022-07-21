class Solution {
public:
    void dfs(int node,vector<vector<int>>& v,vector<int>& vis, int& ccelem)
    {
        vis[node] = 1;
        ccelem++;
        
        for(auto child:v[node])
        {
            if(vis[child]==0)
                dfs(child,v,vis,ccelem);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        
        vector<vector<int>> v(n);
        
        for(int i=0;i<edges.size();i++)
        {   
            int a = edges[i][0];
            int b = edges[i][1];
            
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        vector<int> vis(n,0);
        
        int total=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int ccelem=0;
                dfs(i,v,vis,ccelem);
                ans = ans + 1LL*total*ccelem;
                total+=ccelem;
            }
        }
        
        return ans;
    }
};