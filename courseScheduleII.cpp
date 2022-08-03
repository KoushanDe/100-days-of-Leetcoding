class Solution {
public:
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto prereq:prerequisites)
        {
            int a = prereq[1];
            int b = prereq[0];
            
            graph[a].push_back(b);
            indegree[b]++;
        }
        
        vector<int> toposort;
        
        bfs(graph,indegree,toposort);
        
        
        if(toposort.size()==numCourses)
            return toposort;
        else
            return {};
    }
};