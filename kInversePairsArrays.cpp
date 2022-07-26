//LEETCODE HARD REALLY HARD BECAUSE TLE IN MEDIUM SOLUTION(O(K*K*N))
class Solution {
public:
    int mod = 1000000007;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
            
            if(j>=i)
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod)%mod;
            }
        }
        
        return dp[n][k]%mod;
    }
};