#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row=0;
        
        for(int i=0;i<m;i++)
        {
            if(target<=matrix[i][n-1])
            {
                row=i;
                break;
            }
        }
        
        int low = 0,high = n-1;
        while(low<=high)
        {
            int mid = (high+low)/2;
            
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]>target)
                high = mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};