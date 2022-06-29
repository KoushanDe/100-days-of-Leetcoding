#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int lo=0;
        int hi=n-2;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            
            if(mid%2==1)
            {
                if(nums[mid]==nums[mid-1])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            else
            {
                if(nums[mid]==nums[mid+1])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
        }
        
        return nums[lo];
    }
};