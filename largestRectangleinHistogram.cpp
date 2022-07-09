#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> nsr;
        vector<int> nsl;
        int maxarea = INT_MIN;
        int n = heights.size();
        
        int i=0;
        
        while(i<n)
        {
            if(st.empty())
            {
                nsl.push_back(-1);
            }
            else
            {
                if(heights[st.top()]<heights[i])
                {
                    nsl.push_back(st.top());
                }
                else
                {
                    st.pop();
                    continue;
                }
            }
            st.push(i);
            i++;
        }
        
        i=n-1;
        st = stack<int>();
        while(i>=0)
        {
            if(st.empty())
            {
                nsr.push_back(n);
            }
            else
            {
                if(heights[st.top()]<heights[i])
                {
                    nsr.push_back(st.top());
                }
                else
                {
                    st.pop();
                    continue;
                }
            }
            st.push(i);
            i--;
        }
        reverse(nsr.begin(),nsr.end());
        
        for(i=0;i<n;i++)
        {   
            //cout<<nsl[i]<<" "<<nsr[i]<<endl;
            maxarea = max(maxarea,heights[i]*(nsr[i]-nsl[i]-1));
        }
        return maxarea;
    }
};

//OPTIMAL
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        
        int maxarea=0;
        int n = heights.size();
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if(st.empty()) width=i;
                else width = i-st.top()-1;
                
                maxarea = max(maxarea,height*width);
                
            }
            st.push(i);
        }
        
        return maxarea;
    }
};