#include<bits/stdc++.h>
using namespace std;

/*BRUTE FORCE APPROACH USING PRIORITY QUEUE*
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> maxminwindows;
    
    for(int k=1;k<=n;k++)
    {
        int maxminwindow;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<k;i++)
        {
            pq.push({a[i],i});
        }

        maxminwindow = pq.top().first;

        for(int i=k;i<a.size();i++)
        {
            pq.push({a[i],i});

            while(i>pq.top().second+k-1)
                pq.pop();

            maxminwindow = max(maxminwindow,pq.top().first);
        }

        maxminwindows.push_back(maxminwindow);
    }
    
    return maxminwindows;
}*/