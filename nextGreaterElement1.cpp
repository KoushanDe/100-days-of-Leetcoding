class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        
        int i = nums2.size()-1;
        unordered_map<int,int> ans2;
        while(i>=0)
        {
            if(st.empty())
            {
                ans2[nums2[i]]=-1;
            }
            else
            {
                if(nums2[i]<st.top())
                {
                    ans2[nums2[i]]=st.top();
                }
                else
                {
                    while(!st.empty())
                    {
                        if(nums2[i]<st.top())
                        {
                            ans2[nums2[i]]=st.top();
                            break;
                        }
                        st.pop();
                    }
                    continue;
                }
            }

            st.push(nums2[i--]);
        }
        
        vector<int> ans;
        
        for(auto num:nums1)
        {
            if(ans2.find(num)!=ans2.end())
                ans.push_back(ans2[num]);
        }
        
        return ans;  
    }
};