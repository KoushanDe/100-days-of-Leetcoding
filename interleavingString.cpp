class Solution {
public:
    /**MEMOISATION**
    bool f(string s1, string s2, int i, int j,string s3,vector<vector<int>>& dp)
    {
        if(i==0&&j==0)
            return true;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool s1match=false,s2match=false;
        if(i>0&&s1[i-1]==s3[i+j-1])
            s1match = f(s1,s2,i-1,j,s3,dp);
        if(j>0&&s2[j-1]==s3[i+j-1])
            s2match = f(s1,s2,i,j-1,s3,dp);
        
        return dp[i][j]=s1match|s2match;
    }
    **/
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n1,n2,n3;
        n1=s1.size();
        n2=s2.size();
        
        //vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        //vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
        vector<bool> curr(n2+1,false),prev(n2+1,false);
        
        prev[0] = true;
        curr[0] = true;
        
        for(int i=0;i<=s1.size();i++)
        {
            for(int j=0;j<=s2.size();j++)
            {   
                if(i==0&&j==0) continue;
                
                bool s1match=false,s2match=false;
                if(i>0&&s1[i-1]==s3[i+j-1])
                    s1match = prev[j];
                if(j>0&&s2[j-1]==s3[i+j-1])
                    s2match = curr[j-1];

                curr[j]=s1match||s2match;
            }
            prev = curr;
        }
        
        return prev[n2];
    }
};