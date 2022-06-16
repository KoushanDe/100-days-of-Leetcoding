#include<bits/stdc++.h>
using namespace std;
/**TABULATION 2nd type O(n^2)
int longestIncreasingSubsequence(int arr[], int n)
{    
    vector<int> dp(n,1); //all the elements itself are LIS of size 1
    int lis=1;
    for(int ind=0;ind<n;ind++)
    {
        for(int pvind=0;pvind<ind;pvind++)
        {
            if(arr[ind]>arr[pvind])
            {
                dp[ind] = max(1+dp[pvind],dp[ind]);
                lis = max(lis,dp[ind]);
            }
        }
    }
    return lis;
}*/

/**BINARY SEARCH SOLUTION O(NlogN)**/
int longestIncreasingSubsequence(int arr[], int n)
{    
    vector<int> temp;
    for(int ind=0;ind<n;ind++)
    {    
        int index = lower_bound(temp.begin(),temp.end(),arr[ind])-temp.begin();
        if(index==temp.size())
            temp.push_back(arr[ind]);
        else
            temp[index]=arr[ind];
    }
    return temp.size();
}
