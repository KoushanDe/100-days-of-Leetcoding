// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int row1[], int row2[], int m, int n, int k)
    {
        if(m>n) return kthElement(row2,row1,n,m,k);
        
        
        if(m==0)
            return row2[k-1];
        
        int partLen= k;
        
        int low = max(0,k-n);
        int high = min(m,k);
        
        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = partLen-cut1;
            
            int l1 = cut1>0?row1[cut1-1]:INT_MIN;
            int l2 = cut2>0?row2[cut2-1]:INT_MIN;
            int r1 = cut1<m?row1[cut1]:INT_MAX;
            int r2 = cut2<n?row2[cut2]:INT_MAX;
            
            //cout<<"iteration "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
            
            if(l1<=r2&&l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        
        return 0;
    }
};
