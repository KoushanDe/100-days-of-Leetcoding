#include<bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> freq(n,1);
    int maxlen = 1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&1+dp[j]>=dp[i])
            {    
                if(1+dp[j]>dp[i])
                    freq[i] = freq[j];
                else
                    freq[i] += freq[j];
                dp[i]=1+dp[j];
            } 
        }
        maxlen = max(maxlen,dp[i]);
    }
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxlen)
            count+=freq[i];
    }
    return count;
}