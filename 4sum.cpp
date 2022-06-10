#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return {};
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size()-3;i++)
        {   
            for(int j=i+1;j<nums.size()-2;j++)
            {   
                int left = j+1;
                int right = nums.size()-1;
                
                while(left<right)
                {   
                    long long sum = (long long)(nums[i]);
                    sum+=(long long)(nums[j]);
                    sum+=(long long)(nums[left]);
                    sum+=(long long)(nums[right]);
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left+1<nums.size()&&nums[left+1]==nums[left])
                        left++;
                        left++;
                        while(right-1>j&&nums[right-1]==nums[right])
                        right--;
                        right--;
                    }
                    else if(sum<target)
                        {
                        while(left+1<nums.size()&&nums[left+1]==nums[left])
                        left++;
                        left++;
                    }
                    else
                        {
                        while(right-1>j&&nums[right-1]==nums[right])
                        right--;
                        right--;
                    }
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])
                        j++;
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])
                        i++;
        }
        
        return ans;    
    }
};