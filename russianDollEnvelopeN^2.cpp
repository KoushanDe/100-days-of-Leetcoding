#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        
        int n = envelopes.size();
        
        vector<int> dp(n+1,1);
        
        int maxm = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]&&
                  envelopes[i][1]>envelopes[j][1]
                  &&dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    maxm = max(maxm,dp[i]);
                }
            }
        }
        
        
        return maxm;
    }
};