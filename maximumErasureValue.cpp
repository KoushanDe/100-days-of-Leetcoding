#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_map<int,int> freq;
        int sum=0,maxm=0;
        
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()&&i<=j)
        {
            if(freq[nums[j]]==0)
            {
                sum+=nums[j];
                freq[nums[j]]++;
                j++;
                maxm=max(sum,maxm);
            }
            else
            {
                sum-=nums[i];
                freq[nums[i]]--;
                i++;
            }
        }
        return maxm;
    }
};