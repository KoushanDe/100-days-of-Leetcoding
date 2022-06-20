#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            int sum = -nums[i];
            
            while(j<k)
            {
                if(nums[j]+nums[k]==sum)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j+1]==nums[j]) j++;
                    j++;
                    while(j<k&&nums[k-1]==nums[k]) k--;
                    k--;
                }
                else if(nums[j]+nums[k]>sum)
                {
                    while(j<k&&nums[k-1]==nums[k]) k--;
                    k--;
                }
                else
                {
                    while(j<k&&nums[j+1]==nums[j]) j++;
                    j++;
                }
            }
            
            while(i<n-1&&nums[i+1]==nums[i]) i++;
        }
        
        return ans;
    }
};