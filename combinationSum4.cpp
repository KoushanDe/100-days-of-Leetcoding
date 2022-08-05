class Solution {
public:
    int f(vector<int>& nums, int target,vector<int>&dp)
    {
        if(target==0)
            return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        int comb = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
                comb += f(nums,target-nums[i],dp);
        }
         
        return dp[target]=comb;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return f(nums,target,dp);
    }
};