class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0||target>nums[nums.size()-1]||target<nums[0]) return {-1,-1};
        
        int ind1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin(); 
        
        if(nums[ind1]!=target) return {-1,-1};
        
        int ind2 = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        ind2--;
        
        return {ind1,ind2};
    }
};