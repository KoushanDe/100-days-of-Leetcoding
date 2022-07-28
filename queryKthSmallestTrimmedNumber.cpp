class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int numsize = nums[0].size();
        
        for(int i=0;i<queries.size();i++)
        {
            int k = queries[i][0];
            int trim = queries[i][1];
            priority_queue<pair<string,int>> temp;
            
            for(int j=0;j<nums.size();j++)
            {
                temp.push({nums[j].substr(numsize-trim,trim),j});
                if(temp.size()>k)
                    temp.pop();
            }
            //sort(temp.begin(),temp.end());
            ans.push_back(temp.top().second);
        }
        
        return ans;
    }
};