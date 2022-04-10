#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void subset2(vector<int>&nums,vector<int>&ds,vector<vector<int>>& ans,int index)
    {
        ans.push_back(ds);
        
        for(int i = index;i<nums.size();i++)
        {
            if(i>index&&nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            subset2(nums,ds,ans,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        
        subset2(nums,ds,ans,0);
        return ans;
    }
};