class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int maxm = nums[n-1];
        
        int sum=0;
        int i=0;
        int count=0;
        
        while(sum<maxm&&i<n)
        {   
            if(nums[i]-sum<=0)
            {
                i++;
                continue;
            }
            sum+=(nums[i]-sum);
            i++,count++;
        }
        
        return count;
    }
};