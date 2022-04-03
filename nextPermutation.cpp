#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0)
        {   
            
            if(nums[i]>nums[i-1])
            {   
                int j;
                for(j=nums.size()-1;j>=i;j--)
                {
                    if(nums[j]>nums[i-1])
                        break;
                }
                swap(nums[j],nums[i-1]);
                break;
            }
            i--;
        }
        reverse(nums.begin()+i,nums.end()); //here reverse is used instead of sort,
        // because the right array is already sorted in decreasing manner.
    }
};