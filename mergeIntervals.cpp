#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>end)
            {
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                end = max(end,intervals[i][1]);
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};