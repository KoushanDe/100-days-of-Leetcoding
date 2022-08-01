class Solution {
public:
    int mod = (int)(1e9+7);
    
    int findWays(int n,vector<int>& dp)
    {   
        if(n<=1)
            return n;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=(findWays(n-1,dp)+findWays(n-2,dp))%mod;
    }
    int countHousePlacements(int n) {
        //vector<vector<long long>> dp(n,vector<long long>(n+2,-1));
        vector<int> dp(n+3,-1);
        
        int ans = findWays(n+2,dp);
        
        return (1LL*ans*ans)%mod;
    }
};