#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int f(vector<int>& num,int index, int k,vector<int>& dp)
{    
    if(index==num.size())return 0;
    if(dp[index]!=-1)return dp[index];
    
    int maxm = INT_MIN;
    int maxele = INT_MIN;
    for(int i=index;i<index+k&&i<num.size();i++
    {
        if(num[i]>maxele)maxele = num[i];
        int sum = maxele*(i-index+1) + f(num,i+1,k,dp);
        if(sum>maxm)maxm=sum;
    }
    return dp[index]=maxm;
}*/

int maximumSubarray(vector<int> &num, int k)
{   
    int n = num.size();
    //vector<int> dp(n,-1);
    vector<int> dp(n+1,0);
    
    for(int index=n-1;index>=0;index--)
    {
        int maxm = INT_MIN;
        int maxele = INT_MIN;
        for(int i=index;i<index+k&&i<num.size();i++)
        {
            if(num[i]>maxele)maxele = num[i];
            int sum = maxele*(i-index+1) + dp[i+1];
            if(sum>maxm)maxm=sum;
        }
        dp[index]=maxm;
    }
  
    return dp[0];
}