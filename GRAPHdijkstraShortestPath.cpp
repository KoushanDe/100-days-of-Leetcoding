vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> graph(vertices);
    
    for(int i=0;i<edges;i++)
    {
        int a = vec[i][0];
        int b = vec[i][1];
        int w = vec[i][2];
        
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    
    vector<int> dist(vertices,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({0,source});
    dist[source]=0;
    
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto child:graph[node])
        {    
            if(dis+child.second<dist[child.first])
            {
                dist[child.first]=dis+child.second;
                pq.push({dis+child.second,child.first});
            }
        }
    }
    
    return dist;
}
