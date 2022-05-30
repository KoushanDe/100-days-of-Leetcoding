#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int quo = 0;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        if(dividend==INT_MIN&&divisor==1) return INT_MIN;
        
        long int dvdnd = abs(dividend);
        long int dvsor = abs(divisor);
        
        while(dvdnd>=dvsor)
        {
            long int mul = dvsor, temp = 1;
            
            while(mul<=dvdnd-mul)
            {
                mul+=mul;
                temp+=temp;
            }
            quo+=temp;
            dvdnd-=mul;
        }
        
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -quo;
        
        return quo;
    }
};