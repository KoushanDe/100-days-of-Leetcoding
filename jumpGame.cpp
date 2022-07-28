class Solution {
public:
/** MEMOISATION
    bool f(int ind,vector<int>& nums,int n,vector<int>& dp)
    {
        if(ind==n-1)
            return true;
        
        if(dp[ind]!=-1) return dp[ind];
        
        for(int i=1;i<=nums[ind];i++)
        {
            if(ind+i<=n-1)
            {
                if(f(ind+i,nums,n,dp))
                    return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
**/
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        //TABULATION
        /*vector<bool> dp(n,false);
        
        dp[n-1] = true;
        
        for(int ind=n-2;ind>=0;ind--)
        {
            for(int i=1;i<=nums[ind];i++)
            {
                if(ind+i<=n-1)
                {
                    if(dp[ind+i])
                    {
                        dp[ind] = true;
                        break;
                    }                        
                }
            }
        }
        return dp[0];
        */
       //GREEDY why greedy works? because we can take any jump from a position..no tight constraint
        int i=0, maxreach=nums[0];
        
        while(i<n-1&&i<maxreach)
        {
            i++;
            maxreach = max(maxreach,nums[i]+i);
        }
        
        return i==n-1?true:false;
    }
};