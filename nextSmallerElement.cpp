#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{    
    stack<int> st;
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;)
    {
        if(st.empty())
            ans[i]=-1;
        else
        {
            if(st.top()<arr[i])
                ans[i]=st.top();
            else
            {
                st.pop();
                continue;
            }
        }
        st.push(arr[i--]);
    }
    
    return ans;
    
}