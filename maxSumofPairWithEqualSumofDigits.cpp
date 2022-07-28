class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>> digitsum;
        int maxm = -1;
        
        for(int num:nums)
        {
            int copy = num;
            int dsum=0;
            while(copy)
            {
                dsum+=(copy%10);
                copy/=10;
            }
            digitsum[dsum].push(num);
        }
        
        for(auto digisum:digitsum)
        {
            if(digisum.second.size()<2)
                continue;
            else
            {   
                int sum=0;
                sum+=digisum.second.top();
                digisum.second.pop();
                sum+=digisum.second.top();
                maxm = max(sum,maxm);
            }
        }
        
        return maxm;
    }
};