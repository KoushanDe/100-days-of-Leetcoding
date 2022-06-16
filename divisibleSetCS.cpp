#include<bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1);
    vector<int> hash(n);
    int last=0;
    int lds=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]%arr[j]==0&&(1+dp[j])>dp[i])
            {
                hash[i]=j;
                dp[i] = 1+dp[j];
                if(dp[i]>lds)
                {
                    lds=dp[i];
                    last=i;
                }
            }
        }
    }
    
    vector<int> ans;
    
    for(int i=0;i<lds;i++)
    {
        ans.push_back(arr[last]);
        last = hash[last];
    }
    return ans;
}