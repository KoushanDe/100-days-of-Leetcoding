#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void subCalc2M1(vector<int> nums,set<vector<int>>& ans,vector<int>& sub,int index)
    {
        if(index>=nums.size())
        {
            ans.insert(sub);
            return;
        }
        
        sub.push_back(nums[index]);
        subCalc2M1(nums,ans,sub,index+1);
        sub.pop_back();
        subCalc2M1(nums,ans,sub,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> sub;
        
        set<vector<int>> temp;
        
        subCalc2M1(nums,temp,sub,0);
        vector<vector<int>> ans(temp.begin(),temp.end());
        return ans;
    }
};