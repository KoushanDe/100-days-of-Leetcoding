class Solution {
public:
    struct compareFreq{
    bool operator()(pair<int,int>& p1, pair<int,int>& p2)
    {
        return p1.second>p2.second; //ulto because priority queue acts ulto from vector
    }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compareFreq> pq;
        //we can also do this question without using custom constructor
        //we can push values to priority queue(minheap) like this {elem.second,elem.first}
        
        for(auto elem:freq)
        {   
            if(pq.size()<k)
                pq.push(elem);
            else if(pq.size()==k&&elem.second>pq.top().second)
            {
                pq.pop();
                pq.push(elem);
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};