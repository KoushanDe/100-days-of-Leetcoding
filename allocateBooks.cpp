#include<bits/stdc++.h>
using namespace std;
bool canAllocate(vector<int>& A,int maxbook,int B)
{
    int count=1;
    int totalBook=0;
    
    for(int i=0;i<A.size();i++)
    {
        //if(A[i]>maxbook)return false; no need as mid is always >= max of A[]s
        
        totalBook+=A[i];
        if(totalBook>maxbook)
        {
            count++;
            totalBook=A[i];
        }
    }
    
    return count<=B;
}

int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int low = *max_element(A.begin(),A.end());
    int high=accumulate(A.begin(),A.end(),0);
    
    int ans=-1;
    while(low<=high)
    {   
        int mid = (low+high)/2;
        
        if(canAllocate(A,mid,B)==true)
        {
            ans=mid;
            high = mid-1;
        }
        else
        low = mid+1;
    }
    
    return ans;
}
