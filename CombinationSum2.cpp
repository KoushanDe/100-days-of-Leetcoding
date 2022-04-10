#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void combSum(vector<int>&cand,vector<int>&ds,vector<vector<int>>& ans,int target,int index)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index;i<cand.size();i++)
        {
            if(cand[i]>target)
                break;
            if(i>index&&cand[i]==cand[i-1])
                continue;
            ds.push_back(cand[i]);
            combSum(cand,ds,ans,target-cand[i],i+1);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        
        combSum(candidates,ds,ans,target,0);
        return ans;
    }
};