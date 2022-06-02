#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for(int j=0;j<matrix[0].size();j++)
        {   
            vector<int> temp;
            for(int i=0;i<matrix.size();i++)
                temp.push_back(matrix[i][j]);
            ans.push_back(temp);
        }
        return ans;
    }
};