#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool isValid(vector<vector<int>>&grid,int i,int j)
    {   
        int n = grid.size();
        if(i<0||i>=n||j<0||j>=n)return false;
        if(grid[i][j]==1)return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        int dirI[8] = {0,1,1,1,0,-1,-1,-1}; 
        int dirJ[8] = {1,1,0,-1,-1,-1,0,1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        int dist=1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        q.push({-1,-1});
        
        while(!q.empty())
        {   
            pair<int,int> temp = q.front();
            int i=temp.first,j=temp.second;
            q.pop();
            if(i==-1&&j==-1)
            {   
                if(!q.empty())
                {dist++;
                q.push({-1,-1});
                continue;}
                else
                    break;
            }
            
            if(i==n-1&&j==n-1)return dist;
            
            for(int k=0;k<8;k++)
            {
                if(isValid(grid,i+dirI[k],j+dirJ[k])&&vis[i+dirI[k]][j+dirJ[k]]==0)
                {
                    vis[i+dirI[k]][j+dirJ[k]]=1;
                    q.push({i+dirI[k],j+dirJ[k]});
                }
            }
        }
        return -1;
    }
};