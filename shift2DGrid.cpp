#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        int m = grid[0].size();
        int n = grid.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val = i*m+j+k;
                int row = val/m;
                int col = val%m;
                
                if(row>=n)
                    row = row%n;
                
                ans[row][col] = grid[i][j];
            }
        }
        
        return ans;
    }
};