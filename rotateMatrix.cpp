#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int temp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                swap(matrix[i][j],matrix[i][m-1-j]);
            }
        }
    }
};