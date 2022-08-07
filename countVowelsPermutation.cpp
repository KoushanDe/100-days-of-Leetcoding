int mod = (int)(1e9+7);

class Solution {
public:
    /**MEMOISATION**
    int calc(int ind, int prev,int n,vector<vector<int>>& dp)
    {   
        if(ind == n)
            return 1;
        
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        
        int ways = 0;
        if(prev==0)
        {
            for(int i=1;i<=5;i++)
            {
                ways=(ways+calc(ind+1,i,n,dp))%mod;
            }
        }
        else if(prev==1)
        {
            ways=(ways+calc(ind+1,2,n,dp))%mod;
        }
        else if(prev==2)
        {
            ways=(ways+calc(ind+1,1,n,dp))%mod;
            ways=(ways+calc(ind+1,3,n,dp))%mod;
        }
        else if(prev==3)
        {
            for(int i=1;i<=5;i++)
            {   
                if(i!=3)
                ways=(ways+calc(ind+1,i,n,dp))%mod;
            }
        }
        else if(prev==4)
        {
            ways=(ways+calc(ind+1,3,n,dp))%mod;
            ways=(ways+calc(ind+1,5,n,dp))%mod;
        }
        else
        {
            ways=(ways+calc(ind+1,1,n,dp))%mod;
        }
        
        return dp[ind][prev]=ways;
    }
    **/
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,0));
        
        for(int prev=0;prev<=5;prev++)
            dp[n][prev]=1;
        
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int prev = 5;prev>=0;prev--)
            {
                int ways = 0;
                if(prev==0)
                {
                    for(int i=1;i<=5;i++)
                    {
                        ways=(ways+dp[ind+1][i])%mod;
                    }
                }
                else if(prev==1)
                {
                    ways=(ways+dp[ind+1][2])%mod;
                }
                else if(prev==2)
                {
                    ways=(ways+dp[ind+1][1])%mod;
                    ways=(ways+dp[ind+1][3])%mod;
                }
                else if(prev==3)
                {
                    for(int i=1;i<=5;i++)
                    {   
                        if(i!=3)
                        ways=(ways+dp[ind+1][i])%mod;
                    }
                }
                else if(prev==4)
                {
                    ways=(ways+dp[ind+1][3])%mod;
                    ways=(ways+dp[ind+1][5])%mod;
                }
                else
                {
                    ways=(ways+dp[ind+1][1])%mod;
                }

                dp[ind][prev]=ways;
            }
        }
        return dp[0][0];
    }
};