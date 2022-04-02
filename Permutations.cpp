#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    void findPermutes(vector<int>& nums,vector<vector<int>>& ans,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            findPermutes(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        findPermutes(nums,ans,0);
        
        return ans;
    }
};

//Alternative approach
// let the string is 123
// apply recursion
// pick 1 or pick 2 or pick 3
// keep a map of indeces you pick, and a list to add the numbers
// if you pick index 0 map[0] = true
// loop through each number and see whether it is already picked or not
// if not picked, pick and put true in corresponding map position
// list size == given string size, add list to ans, return
// to backtrack remove the selected number from list and corresponding index
// from map after each iteration