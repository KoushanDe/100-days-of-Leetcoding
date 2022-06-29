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
            
            if(mid%2==1) //odd
            {
                if(nums[mid]==nums[mid-1])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            else //even
            {
                if(nums[mid]==nums[mid+1])
                    lo=mid+1;
                else
                    hi=mid-1;
            }

            //here there is a cool trick to avoid writing both even and odd conditions
            /*
            if(nums[mid]==nums[mid^1]) //odd number xor 1 = even number before it & even number xor 1 = odd number after it  11^1 = 10, 10^1=11
                lo=mid+1;
            else
                hi=mid-1;
            */
        }
        
        return nums[lo];
    }
};