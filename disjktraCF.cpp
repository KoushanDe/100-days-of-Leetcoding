#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    
    vector<int> dist(n+1,INT_MAX),parent(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1]=0;
    
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        //cout<<dis<<" "<<node<<endl;
        pq.pop();
        
        for(auto p:adj[node])
        {
            int wt = p.second;
            int child = p.first;
            
            if(dis+wt<dist[child])
            {
                dist[child]=dis+wt;
                parent[child]=node;
                pq.push({dist[child],child});
            }
        }
    }
    
    if(dist[n]==INT_MAX)
        cout<<-1<<endl;
    else
    {
        vector<int> v;
        int node = n;
        while(node!=-1)
        {
            v.push_back(node);
            node = parent[node];
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}