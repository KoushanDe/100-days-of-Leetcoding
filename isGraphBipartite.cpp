#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int vis[],int col[], int v, int c)
    {
        vis[v] = 1;
        col[v] = c;
        
        for(int child : graph[v])
        {
            if(vis[child]==0)
            {
                if(dfs(graph,vis,col,child,!c)==false)
                    return false;
            }
            else
            {
                if(col[v]==col[child])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int vis[101] = {0};
        int col[101] = {0};
        
        for(int i=0;i<graph.size();i++)
        {   
            if(vis[i]==0)
            {
                if(dfs(graph,vis,col,i,0)==false)
                    return false;
            }
        }
        return true;
    }
};