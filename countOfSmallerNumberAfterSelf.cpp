//Fenwick tree approach
class Solution {
public:
    void update(int ind,vector<int>& BIT){
        while(ind<=BIT.size()){
            BIT[ind]++;
            ind += ind & -ind;
        }
    }
 
    // BIT answer
    int answer(int ind,vector<int>& BIT){
        int ans = 0;
        while(ind>0){
            ans+=BIT[ind];
            ind -= ind & -ind;
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> bit(20005,0);
        
        for(int i=0;i<nums.size();i++)
            nums[i]+=10001;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] = answer(nums[i]-1,bit);
            update(nums[i],bit);
        }
        
        return ans;
    }
};