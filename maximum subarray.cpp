#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxm=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxm = max(maxm,sum);
            if(sum<0)
                sum=0;
        }
        return maxm;
    }
};