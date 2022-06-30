#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        double median=0.00;
        
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        
        
        if(n1==0)
            return (double)(nums2[n2/2]+nums2[(n2-1)/2])/2.00;
        
        // if(n2==0)
        //     return (double)(nums1[n1/2]+nums1[(n1-1)/2])/2.00; 
        //notnecessary as n1<n2 always
        
        int partLen= (n1+n2+1)/2; //works for even as well as odd length
        cout<<partLen<<endl;
        
        int low = 0;
        int high = n1;
        
        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = partLen-cut1;
            
            int l1 = cut1>0?nums1[cut1-1]:INT_MIN;
            int l2 = cut2>0?nums2[cut2-1]:INT_MIN;
            int r1 = cut1<n1?nums1[cut1]:INT_MAX;
            int r2 = cut2<n2?nums2[cut2]:INT_MAX;
            
            if(l1<=r2&&l2<=r1)
            {
                if((n1+n2)%2==0)
                {
                    median= (double)(max(l1,l2)+min(r1,r2))/2.00;
                    return median;
                }
                else
                {
                    median= (double)(max(l1,l2));
                    return median;
                }
            }
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        
        return median;
    }
};