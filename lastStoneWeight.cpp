#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        
        priority_queue<int> stonespq;
        
        for(int i=0;i<stones.size();i++)
        {
            stonespq.push(stones[i]);
        }
        
        int max = stonespq.top();
        stonespq.pop();
        int max2 = stonespq.top();
        stonespq.pop();
        
        while(!stonespq.empty())
        {
            stonespq.push(max-max2);
            max = stonespq.top();
            stonespq.pop();
            max2 = stonespq.top();
            stonespq.pop();
        }
        
        return max-max2;
    }
};