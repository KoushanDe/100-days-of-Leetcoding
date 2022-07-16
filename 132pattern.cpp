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

//NEXT GREATER ELEMENT IN RIGHT APPROACH
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int s3 = INT_MIN;
       int n = nums.size();
        stack<int>s;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i]<s3)
                return true;
            else
            {
                while(!s.empty() && nums[i]>s.top())
                {
                    s3 = max(s3,s.top());
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};