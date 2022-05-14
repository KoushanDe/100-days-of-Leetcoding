#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
	for(vector<int>it:times)
	{
		adj[it[0]].push_back({it[1],it[2]});
	}

	vector<int>dist(n+1,INT_MAX);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>ans;
	dist[k]=0;
	ans.push({k,0});
	while(!ans.empty()){
		auto it=ans.top();
		ans.pop(); 
		for(auto p:adj[it.first]){
			if(dist[it.first]+p.second<dist[p.first]){
				dist[p.first]=dist[it.first]+p.second;
				ans.push({p.first,dist[p.first]});
			}
		}  
	}    
	int maxi=INT_MIN;  
	for(int i=1;i<=n;i++){
		if(dist[i]==INT_MAX)
			return -1;
		else
			maxi=max(maxi,dist[i]);
	}

	return maxi;
    }
};