#include<bits/stdc++.h>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
        for(int i=1;i<grid.size();i++)
        {
            grid[i][0] = grid[i-1][0]+grid[i][0];
        }
        for(int j=1;j<grid[0].size();j++)
        {
            grid[0][j] = grid[0][j-1]+grid[0][j];
        }
        
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
                grid[i][j] = grid[i][j-1] + grid[i][j] + grid[i-1][j] - grid[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        sum += grid[row2][col2];
        
        if(row1!=0)
            sum-=grid[row1-1][col2];
        if(col1!=0)
            sum-=grid[row2][col1-1];
        if(row1!=0&&col1!=0)
            sum+=grid[row1-1][col1-1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */