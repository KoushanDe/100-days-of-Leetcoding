#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        int gap = nums1.size()/2;
        while(gap>0)
        {
            int i=0,j=gap;
            
            while(j<nums1.size())
            {
                if(nums1[i]>nums1[j])
                    swap(nums1[i],nums1[j]);
                i++,j++;
            }
            gap = gap==1? 0 : gap/2 + gap%2;
        }
    }
};