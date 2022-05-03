#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=temp[i])
                break;
        }
        if(i==nums.size())
            return 0;
        for(j=nums.size()-1;j>=0;j--)
        {
            if(nums[j]!=temp[j])
                break;
        }
        
        
        return j-i+1;
    }
};