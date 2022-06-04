#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        map<int,int> arr;
        
        for(int i=0;i<nums.size();i++)
        {   
            if(arr.find(target-nums[i])==arr.end())
            arr[nums[i]]=i;
            else
            {
                ans.push_back(i);
                ans.push_back(arr[target-nums[i]]);
            }
        }
        return ans;
    }
};