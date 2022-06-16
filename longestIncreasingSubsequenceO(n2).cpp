#include<bits/stdc++.h>
/**MEMOISATION**
int func(int arr[], int ind, int prevind,int size,vector<vector<int>>& dp)
{
    if(ind==size)
        return 0;
    
    if(dp[ind][prevind+1]!=-1)return dp[ind][prevind+1];
    int notake = func(arr,ind+1,prevind,size,dp);
    int take = 0;
    if(prevind==-1||arr[ind]>arr[prevind])
        take = 1+func(arr,ind+1,ind,size,dp);
    return dp[ind][prevind+1]=max(take,notake);
}*/
int longestIncreasingSubsequence(int arr[], int n)
{    
    vector<int> after(n+1,0), curr(n+1,0);
    
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int pvind=-1;pvind<ind;pvind++)
        {
            int notake = after[pvind+1];
            int take = 0;
            if(pvind==-1||arr[ind]>arr[pvind])
                take = 1+after[ind+1];
            curr[pvind+1]=max(take,notake);
        }
        after = curr;
    }
    return after[-1+1];
}
