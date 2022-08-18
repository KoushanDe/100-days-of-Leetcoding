class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        
        for(auto num:arr)
        {
            freq[num]++;
        }
        int n = arr.size();
        
        priority_queue<int> pq;
        int setsize=0;
        int count=0;
        
        for(auto m:freq)
        {
            pq.push(m.second);
        }
        
        while(count<n/2)
        {
            int c = pq.top();
            pq.pop();
            setsize++;
            count+=c;
        }
        
        return setsize;
    }
};