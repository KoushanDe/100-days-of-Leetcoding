#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum=nums[0];
        int i=0,j=0;
        
        while(i<nums.size()&&j<nums.size())
        {   
            long long n = j-i+1;
            if((long long)(sum*(n)<k))
            {   
                ans+=n;
                j++;
                if(j<nums.size())sum+=nums[j];
            }
            else
            {   
                
                sum-=nums[i];
                i++;
            }
        }
               return ans;
    }
};