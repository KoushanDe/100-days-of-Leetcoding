#include<bits/stdc++.h>
using namespace std;
bool compareFinish(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.second<p2.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities;
    
    for(int i=0;i<start.size();i++)
    {
        activities.push_back({start[i],finish[i]});
    }
    
    sort(activities.begin(),activities.end(),compareFinish);
    
    int count=0;
    int last = 0;
    for(int i=0;i<activities.size();i++)
    {
        if(activities[i].first>=last)
        {
            count++;
            last = activities[i].second;
        }
    }
  
    return count;
}