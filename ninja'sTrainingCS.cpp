#include<bits/stdc++.h>

using namespace std;
/**RECURSIVE APPROACH**/
/*
int func(vector<vector<int>>& points,int index,int last)
{
    if(index<0)return 0;
    
    int maxm=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxm=max(maxm,points[index][i]+func(points,index-1,i));
        }
    }
    
    return maxm;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if(n==0)return 0;
    
    return func(points,n-1,3);
}
/*

/**MEMOISATION APPROACH**/
/*
int func(vector<vector<int>>& points,int index,int last,vector<vector<int>>& dp)
{
    if(index<0)return 0;
    if(dp[index][last]!=0)return dp[index][last];
    
    int maxm=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxm=max(maxm,points[index][i]+func(points,index-1,i,dp));
        }
    }
    
    return dp[index][last]=maxm;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if(n==0)return 0;
    vector<vector<int>> dp(n,vector<int>(4,0));
    return func(points,n-1,3,dp);
}
/*

/**TABULATION METHOD**/
int ninjaTraining(int n, vector<vector<int>> &points)
{
    if(n==0)return 0;
    vector<vector<int>> dp(n,vector<int>(4,0));
    for(int i=0;i<4;i++)
    {    
        int maxi=0;
        for(int j=0;j<3;j++)
        {
            if(j!=i)
            maxi = max(maxi,points[0][j]);
        }
        dp[0][i] = maxi;    
    }
    
    for(int i=1;i<n;i++)
    {    
        
        for(int last=0;last<3;last++)
        {    
            int maxm=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    maxm = max(maxm,points[i][task]+dp[i-1][task]);
                }
            }
            dp[i][last] = maxm;
        }
    }
    
    
    return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}