#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int ans = INT_MIN;
        
        for(auto chr:n)
        {
            ans = max(ans,chr-'0');
        }
        
        return ans;
    }
};