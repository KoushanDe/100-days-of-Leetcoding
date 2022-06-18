#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
/**MEMOISATION**
long long f(string& exp,int i, int j,int isTrue,vector<vector<vector<long long>>>& dp)
{    
    if(i>j) return 0;
    
    if(i==j)
    {
        if(isTrue==1)return exp[i]=='T';
        else return exp[i]=='F';
    }
    
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    
    long long ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2)
    {
        long long LT = f(exp,i,ind-1,1,dp);
        long long LF = f(exp,i,ind-1,0,dp);
        long long RT = f(exp,ind+1,j,1,dp);
        long long RF = f(exp,ind+1,j,0,dp);
        
        if(exp[ind]=='&')
        {
            if(isTrue==1)
                ways = (ways+(LT*RT)%mod)%mod;
            else
                ways = (ways+(LT*RF)%mod+(RT*LF)%mod+(LF*RF)%mod)%mod;
        }
        else if(exp[ind]=='|')
        {
            if(isTrue==1)
                ways = (ways+ (LT*RF)%mod+(RT*LF)%mod+(LT*RT)%mod)%mod;
            else
                ways = (ways +(LF*RF)%mod)%mod;
        }
        else if(exp[ind]=='^')
        {
            if(isTrue==1)
                ways = (ways+(LT*RF)%mod+(RT*LF)%mod)%mod;
            else
                ways = (ways+(LF*RF)%mod+(RT*LT)%mod)%mod;
        }
    }
    return dp[i][j][isTrue]=ways;
}*/
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,0)));
    
    for(int i=0;i<n;i++)
    {
        dp[i][i][0] = (exp[i]=='F');
        dp[i][i][1] = (exp[i]=='T');
    }
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {    
            for(int isTrue=0;isTrue<=1;isTrue++)
            {
                long long ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2)
                {
                    long long LT = dp[i][ind-1][1];
                    long long LF = dp[i][ind-1][0];
                    long long RT = dp[ind+1][j][1];
                    long long RF = dp[ind+1][j][0];

                    if(exp[ind]=='&')
                    {
                        if(isTrue==1)
                            ways = (ways+(LT*RT)%mod)%mod;
                        else
                            ways = (ways+(LT*RF)%mod+(RT*LF)%mod+(LF*RF)%mod)%mod;
                    }
                    else if(exp[ind]=='|')
                    {
                        if(isTrue==1)
                            ways = (ways+ (LT*RF)%mod+(RT*LF)%mod+(LT*RT)%mod)%mod;
                        else
                            ways = (ways +(LF*RF)%mod)%mod;
                    }
                    else if(exp[ind]=='^')
                    {
                        if(isTrue==1)
                            ways = (ways+(LT*RF)%mod+(RT*LF)%mod)%mod;
                        else
                            ways = (ways+(LF*RF)%mod+(RT*LT)%mod)%mod;
                    }
                }
                dp[i][j][isTrue]=ways;
            }
        }
    }
    return dp[0][n-1][1];
}