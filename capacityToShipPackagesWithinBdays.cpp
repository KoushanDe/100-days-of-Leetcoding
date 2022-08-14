#include<bits/stdc++.h>
bool canShip(vector<int>& A,int W,int B)
{
    int day=1;
    int wt=0;
    
    for(int i=0;i<A.size();i++)
    {
        wt+=A[i];
        if(wt>W)
        {
            day++;
            wt=A[i];
        }
    }
    
    return day<=B;
}
int Solution::solve(vector<int> &A, int B) {
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(canShip(A,mid,B))
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    
    return low;
}
