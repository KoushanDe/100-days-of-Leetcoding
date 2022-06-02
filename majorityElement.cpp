#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem=nums[0];
        int count = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==elem)
                count++;
            else
            {
                count--;
                if(count == 0)
                {
                    elem = nums[i];
                    count++;
                }
            }
        }
        
        return elem;
    }
};