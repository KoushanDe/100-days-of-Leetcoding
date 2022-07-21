class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& dfsvis){
        
        vis[node]=1;
        
        dfsvis[node] = 1;
        
        for(auto child:graph[node])
        {
            if(vis[child]==0)
            {
                if(dfs(child,graph,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[child]==1)
                return true;
        }
        
        dfsvis[node] = 0;
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(auto prereq:prerequisites)
        {
            int a = prereq[1];
            int b = prereq[0];
            
            graph[a].push_back(b);
        }
        
        vector<int> vis(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {   
            if(vis[i]==0)
            {
                if(dfs(i,graph,vis,dfsvis))
                return false;
            }
        }
        
        return true;
    }
};