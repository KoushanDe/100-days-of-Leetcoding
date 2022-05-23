#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {0};
        
        for(int i : nums)
            freq[i]++;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {   
            if(freq[j]>0)
            {
                nums[i] = j;
                freq[j]--;
            }
            else
            {
                j++;
                i--;
            }
        }
    }
};