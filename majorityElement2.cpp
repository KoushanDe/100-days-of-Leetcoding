#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int elem=nums[0],count=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(elem == nums[i])
                count++;
            else
            {
                if(count>nums.size()/3)
                {
                    ans.push_back(elem);
                }
                
                elem = nums[i];
                count=1;
            }
        }
        if(count>nums.size()/3)
            ans.push_back(elem);
        
        return ans;
    }
};