#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void subCalc(vector<int> nums,vector<vector<int>>& ans,vector<int>& sub,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(sub);
            return;
        }
        
        sub.push_back(nums[index]);
        subCalc(nums,ans,sub,index+1);
        sub.pop_back();
        subCalc(nums,ans,sub,index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        
        subCalc(nums,ans,sub,0);
        return ans;
    }
};