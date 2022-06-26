class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int sum=0;
        int i=0,j=0;
        
        while(i<nums.size()&&j<nums.size())
        {
            
            sum+=nums[j];
            //cout<<sum<<endl;
            if(sum>=target)
            {   
                len = min(len,j-i+1);
                sum-=nums[i];
                i++;
                sum-=nums[j];
            }
            else
                j++;
            //cout<<i<<" "<<j<<" "<<sum<<endl;

        }
        
        return len==INT_MAX?0:len;
    }
};