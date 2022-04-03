#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0,curr=0;
        int ans=0;
        
        for(int i=0;i<bank.size();i++)
        {
            curr=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                    curr++;
            }
            if(curr>0)
            {
                ans+=prev*curr;
                prev=curr;
            }
        }
        return ans;
    }
};
