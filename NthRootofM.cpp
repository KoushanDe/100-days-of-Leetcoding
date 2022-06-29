#include <bits/stdc++.h>
using namespace std;
double multiply(double m, int n)
{
    double mul = 1.0;
    
    while(n--)
    {
        mul=mul*m;
    }
    return mul;
}
double findNthRootOfM(int n, long long m) {
	double lo = 1;
    double hi = m;
    double epsilon = 1e-7;
    while(hi-lo>epsilon)
    {
        double mid = (hi+lo)/2.0;
        
        if(multiply(mid,n)>(double)m)
            hi=mid;
        else
            lo=mid;
    }
    
    return lo;
}
