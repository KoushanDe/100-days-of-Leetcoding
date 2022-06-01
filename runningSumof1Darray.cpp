#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rsum;
        rsum.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            rsum.push_back(rsum[i-1]+nums[i]);
        }
        
        return rsum;
    }
};