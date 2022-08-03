class Solution {
public:
    long long mod = (long long)(1e9+7);
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<long long> times(n,LONG_MAX),ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        times[0]=0;
        ways[0]=1;
        
        while(!pq.empty())
        {
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            
            for(auto p:adj[node])
            {
                long long child = p.first;
                long long t = p.second;
                if(time+t<times[child])
                {
                    times[child]=time+t;
                    ways[child]=ways[node];
                    pq.push({time+t,child});
                }
                else if(time+t==times[child])
                    ways[child]= (ways[child]+ways[node])%mod;
            }
        }
        
        
        return ways[n-1]%mod;
    }
};