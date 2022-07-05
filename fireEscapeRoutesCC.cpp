#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int& cap)
{
    vis[node]=1;
    cap++;
    
    for(auto child:graph[node])
    {
        if(vis[child]==0)
        dfs(graph,vis,child,cap);
    }
}

int main() {
	int T;
	
	int mod = (int)(1e9+7);
	
	cin>>T;
	while(T--)
	{
	    int n,m;
	    
	    cin>>n>>m;
	    
	    vector<vector<int>> graph(n+1);
	    vector<int> vis(n+1,0);
	    
	    while(m--)
	    {
	        int a,b;
	        cin>>a>>b;
	        graph[a].push_back(b);
	        graph[b].push_back(a);
	    }
	    
	    int cc=0;
	    long long ways=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        if(vis[i]==0)
	        {
	            int cap=0;
	            dfs(graph,vis,i,cap);
	            cc++;
	            ways = (1LL*ways*cap)%mod;
	        }
	    }
	    
	    cout<<cc<<" "<<ways<<endl;
	}
	return 0;
}
