#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sorting array to determine median value
        //why median? because MD about median is less then MD about mean. STAT KNOWLEDGE
        
        int n = nums.size();
        
        if(n%2==1)
        {
            int mid = nums[n/2];
            int ans=0;
            
            for(int i=0;i<n;i++)
                ans = ans + abs(mid-nums[i]);
            
            return ans;
        }
        else
        {
            int mid1 = nums[n/2];
            int mid2 = nums[n/2-1];
            
            int ans1=0,ans2=0;
            
            for(int i=0;i<n;i++)
                ans1 = ans1 + abs(mid1-nums[i]);
            
            for(int i=0;i<n;i++)
                ans2 = ans2 + abs(mid2-nums[i]);
            
            return min(ans1,ans2);
        }
    }
};