#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0, maxm=INT_MIN;
        long long m = 1000000007;
        long long onesum=0;
        long long onemax;
        for(int i=0;i<arr.size();i++)
        {
            onesum+=arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            maxm=max(maxm,sum);
            if(sum<0)
                sum=0;
        }
        onemax=maxm;
        maxm=INT_MIN;
        int j=2,l=k;
        sum=0;
        while(j>0&&l>0)
        {
            j--,l--;
            for(int i=0;i<arr.size();i++)
            {
                sum+=arr[i];
                maxm=max(maxm,sum);
                if(sum<0)
                    sum=0;
            }
        }
        long long twomax=maxm;
        if(onesum>0)
        {   
            if(twomax>onemax)
            {
                maxm=max(twomax,(onemax+onesum*(k-2)+twomax-onemax));
            }
            else
            maxm = onemax + onesum*(k-1);
        }
        return maxm>0?maxm%m:0;
    }
};