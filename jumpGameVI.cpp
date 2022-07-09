class Solution {
public:
    int f(vector<int>& nums, int index, int k,vector<int>& dp)
    {   
        int n = nums.size();
        int maxm = INT_MIN;
        
        if(index==n-1)
            return nums[n-1];
        
        if(dp[index]!=-1) return dp[index];
        
        for(int i=1;i<=k;i++)
        {
            if(index+i<n)
            {
                maxm = max(maxm,f(nums,index+i,k,dp));
            }
        }
        
        return dp[index]=nums[index]+maxm;
    }
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> dp(n,0);
        priority_queue<pair<int,int>> pq;
        dp[n-1] = nums[n-1];
        pq.push({dp[n-1],n-1});
        
        
        for(int index = n-2;index>=0;index--)
        {   
            if(pq.top().second<=index+k)
            {
                dp[index] = nums[index] + pq.top().first;
                pq.push({dp[index],index});
            }
            else
            {
                pq.pop();
                index++;
            }
        }
        return dp[0];
    }
};