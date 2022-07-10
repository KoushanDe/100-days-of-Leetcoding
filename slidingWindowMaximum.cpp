class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxwindow;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        maxwindow.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            
            while(i>pq.top().second+k-1)
                pq.pop();
            
            maxwindow.push_back(pq.top().first);
        }
        
        return maxwindow;
    }
};