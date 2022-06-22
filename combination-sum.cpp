#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void recSum(vector<int>& cand, vector<vector<int>>& ans, vector<int>& list, int t,int index,int&sum)
    {
        if(sum==t)
        {
            ans.push_back(list);
            return;
        }
        else if(sum>t || index>=cand.size())
        {
            return;
        }
        
        sum += cand[index];
        list.push_back(cand[index]);
        recSum(cand,ans,list,t,index,sum);
        sum-=cand[index];
        list.pop_back();
        recSum(cand,ans,list,t,index+1,sum);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        int sum = 0;
        //sort(candidates.begin(),candidates.end()); unnecessary
        recSum(candidates,ans,list,target,0,sum);
        
        return ans;
    }
};