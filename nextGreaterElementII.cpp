class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        
        // for(int i=0;i<n;i++)
        //     nums.push_back(nums[i]); //no need to copy just do the modulo thing to traverse nums twice
            
        int i=nums.size()*2-1;
        while(i>=0)
        {
            if(st.empty())
                ans[i%n]= -1;
            else
            {
                if(st.top()>nums[i%n])
                ans[i%n]=st.top();
                else
                {
                    st.pop();
                    continue;
                }
            }
            st.push(nums[i%n]);
            i--;
        }
        
     return ans;
    }
};