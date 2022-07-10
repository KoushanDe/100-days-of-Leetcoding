#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<vector<int>>& grid, int i, int j)
    {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        
        if(i<0||i==rowsize||j<0||j==colsize||grid[i][j]!=1)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int total=0;
                
        int minute=0;
        int cnt = 0;
        queue<pair<int,int>> q;
        
        int diri[4] = {-1,0,1,0};
        int dirj[4] = {0,1,0,-1};
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    total++;
                else if(grid[i][j]==2)
                {
                    total++;
                    cnt++;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int k=0;k<size;k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int d=0;d<4;d++)
                {
                    if(isPossible(grid,i+diri[d],j+dirj[d]))
                    {   
                        grid[i+diri[d]][j+dirj[d]]=2;
                        q.push({i+diri[d],j+dirj[d]});
                        cnt++;
                    }
                }
            }
            
            if(!q.empty())
                minute++;
        }
    
        return cnt==total?minute:-1;
        
    }
};