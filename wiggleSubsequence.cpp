#include<bits/stdc++.h>
using namespace std;
//DP APPROACH//
class Solution {
public:
    /*MEMOISATION**
    int f(vector<int>& nums,int index, int prevsign,vector<vector<int>>& dp)
    {   
        if(index==nums.size()-1)
            return 1;
        
        if(dp[index][prevsign]!=-1)return dp[index][prevsign];
        
        int maxm=1;
        for(int i=index+1;i<nums.size();i++)
        {
            if(prevsign==0&&nums[i]-nums[index]>0)
            {
                maxm = max(maxm,1+f(nums,i,1,dp));
            }
            else if(prevsign==1&&nums[i]-nums[index]<0)
            {
                maxm = max(maxm,1+f(nums,i,0,dp));
            }
        }
        
        return dp[index][prevsign]=maxm;
    }*/
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        
        vector<vector<int>> dp(nums.size(),vector<int>(2,1));
        
        for(int index=nums.size()-2;index>=0;index--)
        {
            for(int prevsign=0;prevsign<=1;prevsign++)
            {   
                int maxm=1;
                for(int i=index+1;i<nums.size();i++)
                {
                    if(prevsign==0&&nums[i]-nums[index]>0)
                    {
                        maxm = max(maxm,1+dp[i][1]);
                    }
                    else if(prevsign==1&&nums[i]-nums[index]<0)
                    {
                        maxm = max(maxm,1+dp[i][0]);
                    }
                }
                dp[index][prevsign]=maxm;
            }
        }
        
        return max(dp[0][0],dp[0][1]);
        
    }
};