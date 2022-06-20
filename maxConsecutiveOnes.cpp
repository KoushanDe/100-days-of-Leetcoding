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
            {
                count++;
                maxm=max(count,maxm);
            }
            else
            {
                count=0;
            }
        }

        return maxm;
    }
};