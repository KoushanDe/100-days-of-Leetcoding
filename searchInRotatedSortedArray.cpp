#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]>=nums[lo])
            {
                if(nums[lo]<=target&&target<=nums[mid])
                    hi=mid-1;
                else
                    lo=mid+1;
            }
            else
            {
                if(nums[mid]<=target&&target<=nums[hi])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
        }
        
        return -1;
    }
};

//Most probably aditya verma solution
// class Solution {
// public:
    
//     int findMin(vector<int>& nums) {
        
//         int n = nums.size();
        
//         if(nums[0]<=nums[n-1])
//             return 0;
        
//         int low=0;
//         int high = n-1;
        
//         while(low<=high)
//         {
//             int mid = low + (high-low)/2;
            
//             if(nums[mid]<nums[(n+mid-1)%n]&&nums[mid]<nums[(mid+1)%n])
//                 return mid;
//             else if(nums[mid]>=nums[0])
//                 low=mid+1;
//             else
//                 high=mid-1;
//         }
//         return 0;
//     }
    
//     int BS(vector<int>&nums,int target,int low,int high)
//     {
//         while(low<=high)
//         {
//             int mid=low+(high-low)/2;
            
//             if(nums[mid]==target)
//                 return mid;
//             else if(nums[mid]<target)
//                 low = mid+1;
//             else
//                 high=mid-1;
//         }
//         return -1;
//     }
    
//     int search(vector<int>& nums, int target) {
//         int index = findMin(nums);
//         int a,b;
        
//         a=BS(nums,target,0,index-1);
//         b=BS(nums,target,index,nums.size()-1);   
        
        
        
//         return max(a,b);
//     }
// };