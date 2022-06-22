#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{    
    int i=0,j=s.size()-1;
    
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++,j--;
    }
    return true;
}
//palindrome partitioning 1 is same 2 same..but there we need to print all the possible partitions, so no dp..warna same hi hay bro
/**MEMOISATION**
int f(string& s, int index,vector<int>& dp)
{    
    if(index==s.size()) return -1;
    if(dp[index]!=-1) return dp[index];
    int minm=INT_MAX;
    for(int i=index+1;i<=s.size();i++)
    {    
        if(isPalindrome(s.substr(index,i-index))==true)
        {    
            int cuts;
            cuts = 1 + f(s,i,dp);
            if(cuts<minm)minm=cuts;
        }
    }
    return dp[index]=minm;
}*/

int palindromePartitioning(string str) {
    int n = str.size();
    //vector<int> dp(n,-1);
    vector<int> dp(n+1,0);
    dp[n] = -1;
    
    for(int index = n-1;index>=0;index--)
    {
        int minm=INT_MAX;
        for(int i=index+1;i<=str.size();i++)
        {    
            if(isPalindrome(str.substr(index,i-index))==true)
            {    
                int cuts;
                cuts = 1 + dp[i];
                if(cuts<minm)minm=cuts;
            }
        }
        dp[index]=minm;
    }
    return dp[0];
}
