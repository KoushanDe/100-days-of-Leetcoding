#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,subsum,minm;
        int m = cardPoints.size()-k;
        
        accumulate(cardPoints.begin(),cardPoints.begin()+m,sum);
        subsum=sum;
        minm=sum;
        
        for(int i=m;i<cardPoints.size();i++)
        {
            sum+=cardPoints[i];
            subsum = subsum + cardPoints[i] - cardPoints[i-m];
            minm=min(subsum,minm);
        }
        
        return sum-minm;
    }
};