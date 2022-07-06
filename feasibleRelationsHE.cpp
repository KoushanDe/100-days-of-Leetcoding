#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& ccv,int node, int cc)
{
	vis[node]=1;
	ccv[node]=cc;

	for(auto child:graph[node])
	{
		if(vis[child]==0)
		dfs(graph,vis,ccv,child,cc);
	}
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;

		vector<vector<int>> graph(n+1);
		vector<int> vis(n+1);
		vector<int> ccv(n+1);
		vector<pair<int,int>> check;

		for(int i=0;i<k;i++)
		{
			int a,b;
			string op;

			cin>>a>>op>>b;

			if(op=="=")
			{
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
			else
			{
				check.push_back({a,b});
			}
		}

		int cc=0;

		for(int i=1;i<=n;i++)
		{	
			if(vis[i]==0)
			{
				cc++;
				dfs(graph,vis,ccv,i,cc);
			}	
		}

		int flag=0;
		for(auto p:check)
		{
			if(ccv[p.first]==ccv[p.second])
			{
				flag=1;
				break;
			}
		}

		if(flag)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
}