#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int len = 0;
        
        for(auto num:nums)
            sum+=num;
        if(sum == x) return nums.size();
        if(sum<x) return -1;
        int tar = sum - x;
        sum=nums[0];
        
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size())
        {
            //cout<<i<<" "<<j<<" "<<sum<<endl;
            if(sum==tar)
            {
                len = max(len,j-i+1);
                sum-=nums[i];
                i++,j++;
                sum+=nums[j];
            }
            else if(sum<tar)
            {
                j++;
                sum+=nums[j];
            }
            else
            {
                sum-=nums[i];
                i++;
            }
        }
        
        return len==0?-1:nums.size()-len;
    }
};