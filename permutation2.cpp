#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    void findPermutes(vector<int>& nums,set<vector<int>>& ans,int index)
    {
        if(index==nums.size())
        {
            ans.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            findPermutes(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        findPermutes(nums,ans,0);
        vector<vector<int>> vans(ans.begin(),ans.end());
        return vans;
    }
};
