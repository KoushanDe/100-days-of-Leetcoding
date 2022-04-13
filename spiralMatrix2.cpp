#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    void fillArray(int start, vector<vector<int>>& arr, int count, int n)
    {   
        if(start>=(n+1)/2)
            return;
        
        int row=start,col=start;
        while(col<n-start)
        {
            arr[row][col]=count;
            col++;
            count++;
        }
        row++;
        col--;
        while(row<n-start)
        {
            arr[row][col]=count;
            row++;
            count++;
        }
        row--;
        col--;
        while(col>=start)
        {
            arr[row][col]=count;
            col--;
            count++;
        }
        col++;
        row--;
        while(row>start)
        {
            arr[row][col]=count;
            row--;
            count++;
        }
        
        fillArray(start+1,arr,count,n);
    }
    
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        fillArray(0,ans,1,n);
        return ans;
    }
};