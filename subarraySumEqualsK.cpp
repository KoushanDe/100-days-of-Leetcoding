class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumfreq;
        int ans=0;
        if(nums[0]==k)
            ans++;
        
        sumfreq[nums[0]]++;
        //sumfreq[0]=1;
        
        for(int i=1;i<nums.size();i++)
        {   
            nums[i]=nums[i]+nums[i-1];
            
            if(nums[i]==k)
                ans++;
            ans+=sumfreq[nums[i]-k];
            sumfreq[nums[i]]++;
        }
        
        return ans;
    }
};