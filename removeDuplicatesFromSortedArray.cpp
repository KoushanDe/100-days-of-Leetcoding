#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0,j=1;
        
        while(j<nums.size())
        {
            if(nums[j]!=nums[i])
            {
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
            else
                j++;
        }
        
        return i+1;
    }
};