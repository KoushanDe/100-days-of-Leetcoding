#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st;
        int minm = INT_MAX;
        
        int i=0;
        while(i<nums.size())
        {   
            if(st.empty())
                st.push({nums[i],minm});
            else
            {
                if(nums[i]>=st.top().first)
                {
                    st.pop();
                    continue;
                }
                else
                {
                    if(nums[i]>st.top().second)
                        return true;
                }
            }
            st.push({nums[i],minm});
            minm = min(minm,nums[i]);
            i++;
        }
        return false;
    }

};