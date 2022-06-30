#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        
        priority_queue<int> pq;
        
        for(int num:target)
        {
            pq.push(num);
            sum+=num;
        }
        
        while(pq.top()!=1)
        {
            int maxm = pq.top();
            sum-=maxm;
            if(sum==0||sum>maxm) return false;
            pq.pop();
            int old = maxm%sum;
            
            if(old==0&&sum!=1) return false;
            
            
            pq.push(old);
            
            
            
            sum = sum + old; 
        }
        
        return true;
    }
};