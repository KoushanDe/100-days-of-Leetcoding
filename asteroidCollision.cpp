class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty()||asteroids[i]>0)
                st.push(asteroids[i]);
            else
            {
                if(st.top()<0)
                    st.push(asteroids[i]);
                else if(abs(asteroids[i])>st.top())
                {   
                    st.pop();
                        i--;
                }
                else if(abs(asteroids[i])==st.top())
                    st.pop();
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};