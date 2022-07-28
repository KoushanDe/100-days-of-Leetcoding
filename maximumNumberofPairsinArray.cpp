class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> freq(101,0);
        int pairs=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            
            if(freq[nums[i]]==2)
            {
                pairs++;
                freq[nums[i]]=0;
            }
        }
        
        return {pairs,n-pairs*2};
    }
};