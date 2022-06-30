#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool compareDuration(vector<int>& v1, vector<int>& v2)
    {
        if(v1[1]<v2[1])
            return true;
        else if(v1[1]==v2[1])
            return v1[0]<v2[0];
        else
            return false;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),compareDuration);
        
        priority_queue<int> pq;
        
        int currentDuration=0;
        
        for(int i=0;i<courses.size();i++)
        {   
            pq.push(courses[i][0]);
            currentDuration+=courses[i][0];
            
            if(currentDuration>courses[i][1])
            {   
                currentDuration-=pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};