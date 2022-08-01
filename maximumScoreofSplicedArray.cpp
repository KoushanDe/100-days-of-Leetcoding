class Solution {
public:
    int maxSum(vector<int>&nums1,vector<int>&nums2)
    {
        int i=0,j=0,left=0,right=0;
        int sum1=nums1[0];
        int sum2=nums2[0];
        int diff=INT_MIN;
        
        while(true)
        {
            if(sum1>sum2)
            {
                j++;
                i=j;
                if(i==nums1.size()) break;
                sum1=nums1[i];
                sum2=nums2[i];
            }
            else
            {
                if(sum2-sum1>diff)
                {
                    diff=sum2-sum1;
                    left = i;
                    right = j;
                }
                j++;
                if(j==nums1.size()) break;
                sum1+=nums1[j];
                sum2+=nums2[j];
            }
        }
        
        //cout<<left<<" "<<right<<endl;
        
        sum1=sum2=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(i<left||i>right)
            {
                sum1+=nums1[i];
                sum2+=nums2[i];
            }
            else
            {
                sum1+=nums2[i];
                sum2+=nums1[i];
            }
        }
        
        return max(sum1,sum2);  
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==1) return max(nums1[0],nums2[0]);
        
        return max(maxSum(nums1,nums2),maxSum(nums2,nums1));;
    }
};