#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countVowelStrings(int n) {
        array<int,5>dp= {1,1,1,1,1};
        int sum=5;
        for(int i=2;i<=n;i++)
        {   
            array<int,5>temp = dp;
            dp[0] = sum;
            for(int j=0;j<4;j++)
            {
                sum+=(dp[j]-temp[j]);
                dp[j+1] = dp[j]-temp[j];
            }
        }
        return sum;
    }
};