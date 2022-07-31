class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<vector<int>> adjlist(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                adjlist[i].push_back(edges[i]);
        }
        
        vector<int> dist1(n,-1),dist2(n,-1);
        vector<int> vis1(n,0),vis2(n,0);
        
        queue<int> q;
        q.push(node1);
        vis1[node1]=1;
        int dist=0;
        
        while(!q.empty())
        {   
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int node = q.front();
                q.pop();

                dist1[node] = dist;

                for(int child:adjlist[node])
                {
                    if(vis1[child]==0)
                    {
                        vis1[child]=1;
                        q.push(child);
                    }
                }
            }
            dist++;
        }
        
        q.push(node2);
        vis2[node2]=1;
        dist=0;
        while(!q.empty())
        {   
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int node = q.front();
                q.pop();

                dist2[node] = dist;

                for(int child:adjlist[node])
                {
                    if(vis2[child]==0)
                    {
                        vis2[child]=1;
                        q.push(child);
                    }
                }
            }
            dist++;
        }
        
        int node=-1;
        int diff = INT_MAX;
        
        // for(int i=0;i<n;i++)
        //     cout<<dist1[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<dist2[i]<<" ";
        // cout<<endl;
        
        
        for(int i=0;i<n;i++)
        {   
            if(dist1[i]==-1||dist2[i]==-1)
                continue;
            if(max(dist1[i],dist2[i])<diff)
            {
                diff = max(dist1[i],dist2[i]);
                node = i;
            }
        }
        
        return node;
    }
};