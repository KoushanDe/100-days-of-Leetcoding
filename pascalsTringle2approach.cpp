#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        // for(int i=0;i<numRows;i++)
        // {
        //     vector<int> temp;
        //     int num=1;
        //     temp.push_back(num);
        //     for(int j=1;j<=i;j++)
        //     {   
        //         num = num * (i-j+1) / j;
        //         temp.push_back(num);
        //     }
        //     ans.push_back(temp);
        // }
        for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
            }
        }
        return ans;
    }
};