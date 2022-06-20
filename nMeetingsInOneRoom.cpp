// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compareSecond(pair<int,int>& p1,pair<int,int>& p2)
    {
        return p1.second<p2.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        
        for(int i=0;i<n;i++)
        {
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end(),compareSecond);
        
        int count = 1;
        
        int last = meetings[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(meetings[i].first>last)
            {
                count++;
                last = meetings[i].second;
            }
        }
        
        return count;
    }
};
