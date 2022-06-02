#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long negn;
        
        negn = abs(n);
        
        while(negn>0)
        {
            if(negn%2==0)
            {
                x = x*x;
                negn/=2;
            }
            else
            {
                ans = ans * x;
                negn--;
            }
        }
        
        if(n<0)ans=1/ans;
        
        return ans;
    }
};