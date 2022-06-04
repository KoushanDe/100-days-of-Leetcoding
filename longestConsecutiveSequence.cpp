#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
       sort(nums.begin(),nums.end());
        
        int maxcount=1,count = 1;
        
        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i-1]==nums[i])
                continue;
            else if(nums[i-1]==nums[i]-1)
            {
                count++;
                maxcount=max(count,maxcount);
            }
            else
                count=1;
        }
        return maxcount;
    }
};