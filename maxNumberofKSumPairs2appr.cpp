#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
//     int maxOperations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
        
//         int i=0,j=nums.size()-1;
//         int count = 0;
//         while(i<j)
//         {
//             if(nums[i]+nums[j]==k)
//             {
//                 count++;
//                 i++,j--;
//             }
//             else if(nums[i]+nums[j]>k)
//                 j--;
//             else
//                 i++;
//         }
//         return count;
//     }
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count = 0;
        for(int num : nums)
        {
            if(freq[k-num]>0){
                count++;
                freq[k-num]--;
            }
            else
            {
                freq[num]++;
            }
        }
        return count;
    }
};