class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
            
        int i=nums.size()-1;
        while(i>=0)
        {
            if(st.empty())
                ans[i%n]= -1;
            else
            {
                if(st.top()>nums[i])
                ans[i%n]=st.top();
                else
                {
                    st.pop();
                    continue;
                }
            }
            st.push(nums[i]);
            i--;
        }
        
     return ans;
    }
};