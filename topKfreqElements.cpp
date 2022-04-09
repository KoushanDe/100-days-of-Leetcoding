#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    struct compareFreq{
    bool operator()(pair<int,int>& p1, pair<int,int>& p2)
    {
        return p1.second<p2.second;
    }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compareFreq> pq;
        
        for(auto elem:freq)
        {
            pq.push(elem);
        }
        
        while(k>0)
        {
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};