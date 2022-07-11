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
#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> maxminwindows(n,INT_MIN);
    
    vector<int> lse;
    vector<int> rse;
    
    stack<int> st;
    
    for(int i=0;i<n;)
    {
        if(st.empty())
            lse.push_back(-1);
        else
        {
            if(a[i]<=a[st.top()])
            {
                st.pop();
                continue;
            }
            else
                lse.push_back(st.top());
        }
        st.push(i++);
    }
    
    while(!st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;)
    {
        if(st.empty())
            rse.push_back(n);
        else
        {
            if(a[i]<=a[st.top()])
            {
                st.pop();
                continue;
            }
            else
                rse.push_back(st.top());
        }
        st.push(i--);
    }
    reverse(rse.begin(),rse.end());
    
//     for(auto num:rse)
//         cout<<num<<" ";
//     cout<<endl;
//     for(auto num:lse)
//         cout<<num<<" ";
//     cout<<endl;
    
    for(int i=0;i<n;i++)
    {
        int winsize = rse[i] - lse[i] -1;
        
        if(maxminwindows[winsize-1]<a[i])
            maxminwindows[winsize-1]=a[i];
    }

    int prev=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(maxminwindows[i]>prev)
            prev=maxminwindows[i];
        else
            maxminwindows[i]=prev;
    }
    
    return maxminwindows;
}