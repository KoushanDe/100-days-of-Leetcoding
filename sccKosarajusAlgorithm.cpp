//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[],int node, vector<int>& vis, stack<int>& st)
	{
	    vis[node] = 1;
	    
	    for(auto child:adj[node])
	    {
	        if(vis[child]==0)
	        dfs(adj,child,vis,st);
	    }
	    
	    st.push(node);
	}
	void revdfs(vector<vector<int>>& adj,int node, vector<int>& vis)
	{
	    vis[node] = 1;
	    
	    for(auto child:adj[node])
	    {
	        if(vis[child]==0)
	        revdfs(adj,child,vis);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {   
        vector<vector<int>> trans(V);
        
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(adj,i,vis,st);
        }
        
        int scc=0;
        
        for(int i=0;i<V;i++)
        {
            for(int child:adj[i])
            {
                trans[child].push_back(i);
            }
            vis[i]=0;
        }
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(vis[node]==0)
            {
                revdfs(trans,node,vis);
                scc++;
            }
        }
        
        
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends