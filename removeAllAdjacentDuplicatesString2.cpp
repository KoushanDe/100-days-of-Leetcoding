#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
                st.push({s[i],1});
            else
            {
                if(s[i]==st.top().first)
                {
                    st.top().second++;
                }
                else
                    st.push({s[i],1});
            }
            if(st.top().second==k)
                st.pop();
        }
        
        string ans;
        while(!st.empty())
        {   
            for(int i=0;i<st.top().second;i++)
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};