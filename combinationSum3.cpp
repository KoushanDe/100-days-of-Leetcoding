#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void csum3(int k,int n,vector<vector<int>>& ans, vector<int>& list, int last)
    {
        if(k==0&&n==0){
            ans.push_back(list);
            return;
        }
        else if(k<=0)
            return;
        
        for(int i=last+1;i<10;i++)
        {
                if(n-i>=0){
                    list.push_back(i);
                    csum3(k-1,n-i,ans,list,i);
                    list.pop_back();
                }
                else
                    break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> templist;
        
        csum3(k,n,ans,templist,0);
        return ans;
    }
};