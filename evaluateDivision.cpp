#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,map<vector<int>,double>& eqval,int vis[], int nodea,int nodeb, double& ans)
    {
        vis[nodea] = 1;
        if(nodea==nodeb)
            return true;
        for(int child: graph[nodea])
        {   
            if(vis[child]==0)
            {
                ans = ans * eqval[{nodea,child}];
                if(dfs(graph,eqval,vis,child,nodeb,ans)==true)
                return true;
                ans = ans / eqval[{nodea,child}];
            }
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<int>> graph(41);
        map<vector<int>,double> eqval;
        vector<double> ans;
        map<string,int> lettermap;
        
        for(int i=0,index = 1;i<equations.size();i++)
        {
            if(lettermap[equations[i][0]]==0)
            {
                lettermap[equations[i][0]]=index;
                index++;
            }
            if(lettermap[equations[i][1]]==0)
            {
                lettermap[equations[i][1]]=index;
                index++;
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            graph[lettermap[equations[i][0]]].push_back(lettermap[equations[i][1]]);
            graph[lettermap[equations[i][1]]].push_back(lettermap[equations[i][0]]);
            eqval[{lettermap[equations[i][0]],lettermap[equations[i][1]]}] = values[i];
            eqval[{lettermap[equations[i][1]],lettermap[equations[i][0]]}] = 1/values[i];
            eqval[{lettermap[equations[i][0]],lettermap[equations[i][0]]}] = 1;
            eqval[{lettermap[equations[i][1]],lettermap[equations[i][1]]}] = 1;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            double tempans = 1;
            int vis[41] = {0};
            if(lettermap[queries[i][0]]!=0&&lettermap[queries[i][1]]!=0)
            {
                if(dfs(graph,eqval,vis,lettermap[queries[i][0]],lettermap[queries[i][1]],tempans)==true)
                ans.push_back(tempans);
            else
                ans.push_back(-1);
            }
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};