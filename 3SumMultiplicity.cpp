#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int,int> freq;
        long long ans=0;
        int M = 1000000007;
        long long mul;
        
        
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        
        int i=0,j=*max_element(arr.begin(), arr.end());
        
        while(i<=j)
        {   
            if(i<=target-i-j&&target-i-j<=j)
            {   
                int k = target-i-j;
                mul = (freq[i]--);
                mul = mul * (freq[j]--);
                mul = mul * (freq[k]);
                    if(i==k||k==j)
                    {
                        mul/=2;
                        if(i==j)
                            mul/=3;
                    }
                ans=(ans+mul)%M;
                freq[i]++,freq[j]++;
            }
            
            if(2*i+j>target)
            {
                j--;
                i=0;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};