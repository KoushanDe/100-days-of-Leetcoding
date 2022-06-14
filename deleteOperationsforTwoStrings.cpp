#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**MEMOISATION**
    int lcs(string word1, string word2, int ind1, int ind2,vector<vector<int>>& dp)
    {
        if(ind1==0||ind2==0) return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(word1[ind1-1]==word2[ind2-1])
            return dp[ind1][ind2]=1+lcs(word1,word2,ind1-1,ind2-1,dp);
        else
            return dp[ind1][ind2]=max(lcs(word1,word2,ind1,ind2-1,dp),lcs(word1,word2,ind1-1,ind2,dp));
    }*/
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        int len = dp[n][m];
        return n+m-2*len;
    }
};