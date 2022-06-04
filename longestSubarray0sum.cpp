#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    
    if(arr.size()==0)return 0;
    map<int,int> pref;
    int count=0;
    int sum = arr[0];
    pref[sum]=0;
    if(sum==0)count=1;
    for(int i=1;i<arr.size();i++)
    {    
        sum = sum + arr[i];
        if(sum==0)
           count=i+1;
        else if(pref.find(sum)==pref.end())
            pref[sum]=i;
        else{
                 count=max(count,i-pref[sum]);
        }
            
    }
    
    return count;
}