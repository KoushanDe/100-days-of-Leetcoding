#include<bits/stdc++.h>
using namespace std;
int longestBitonicSequence(vector<int>& arr, int n) {
	  vector<int> lis(n,1),lds(n,1); //two dp, one for increasing subq, one for decreasing
    int lbs=1; //stores max len of longest bitonic subq
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&1+lis[j]>lis[i])
                lis[i]=1+lis[j];
        }
    }
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j]&&1+lds[j]>lds[i])
                lds[i]=1+lds[j];
        }
        lbs = max(lbs,lis[i]+lds[i]-1);
    }
    
    
    return lbs;
} 
