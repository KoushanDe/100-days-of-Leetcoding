#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;

	while(T--)
	{
		int n,m;

		cin>>n>>m;

		vector<vector<int>> graph(n+1);
		vector<int> vis(n+1,0);
		vector<int> dist(n+1,0);

		while(m--)
		{
			int a,b;
			cin>>a>>b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		queue<int> q;
		q.push(1);
		vis[1]=1;

		while(!q.empty())
		{	
			int node = q.front();
			q.pop();
			for(auto child:graph[node])
			{
				if(vis[child]==0)
				{
					dist[child]=dist[node]+1;
					vis[child]=1;
					q.push(child);
				}
			}
		}

		cout<<dist[n]<<endl;
	}

	return 0;
}