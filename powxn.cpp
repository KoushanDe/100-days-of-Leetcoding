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

//RECURSIVE
class Solution {
public:
    double multiply(double x, long long n)
    {
        if(n==0) return 1;
        if(n==1) return x;
        
        double mul = multiply(x,n/2);
        mul = mul*mul;
        
        if(n&1)
            mul = mul*x;
        
        return mul;
    }
        
    double myPow(double x, int n) {
        long long pn = abs(n);
        
        double ans = multiply(x,pn);
        
        if(n<0)
            ans = 1/ans;
        
        return ans;
    }
};