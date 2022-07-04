#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph,int node,vector<int>& vis, vector<int>& col,int colour){
	
	vis[node] = 1;
	col[node] = colour;
	
	for(int child:graph[node])
	{
		if(vis[child]==0)
		{
			if(dfs(graph,child,vis,col,!colour)==false)
			return false;
			
		}
		else if(col[node]==col[child])
		return false;
	}
	return true;
}

int main() {
	int T;
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int n,e;
		
		cin>>n>>e;
		
		vector<vector<int>> graph(n+1);
		
		for(int i=0;i<e;i++)
		{
			int v1,v2;
			
			cin>>v1>>v2;
			
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		
		vector<int> vis(n+1,0);
		vector<int> col(n+1,0);
		
		int flag=0;
		
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				if(dfs(graph,i,vis,col,0)==false)
				{
					flag=1;
					break;
				}
			}
		}
		
		cout<<"Scenario #"<<t<<":"<<endl;
		
		if(flag)
		cout<<"Suspicious bugs found!"<<endl;
		else
		cout<<"No suspicious bugs found!"<<endl;
	}
	
	return 0;
}