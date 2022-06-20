#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxm = 0;
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                maxm=max(count,maxm);
                count=0;
            }
        }
        maxm = max(maxm,count);
        return maxm;
    }
};