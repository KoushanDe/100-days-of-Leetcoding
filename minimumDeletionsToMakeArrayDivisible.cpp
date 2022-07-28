class Solution {
public:
    int gcd(int a,int b)
    {
        if(b>a) swap(a,b);
        if(a%b==0) return b;
        
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        
        int num = numsDivide[0];
        
        for(int i=1;i<numsDivide.size();i++)
        {
            num = gcd(num,numsDivide[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>num)
                return -1;
            if(num%nums[i]==0)
                return i;
        }
        
        return -1;
    }
};