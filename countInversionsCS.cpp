#include<bits/stdc++.h>
using namespace std;
long long merge(long long* arr, long long* temp, int left, int mid, int right)
{
    int i,j,k;
    long long count = 0;
    
    i=left;
    j=mid;
    k=left;
    
    while((i <= mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            
            count += (mid-i);
        }
    }
    
    while(i<=mid-1)
        temp[k++] = arr[i++];
    
    while(j<=right)
        temp[k++] = arr[j++];
    
    for(int i=left;i<=right;i++)
        arr[i]=temp[i];
    
    return count;
}

long long mergesort(long long* arr, long long* temp, int left, int right)
{
    int mid;
    long long count=0;
    
    if(right>left)
    {
        mid = (right+left)/2;
        
        count += mergesort(arr,temp,left,mid);
        count += mergesort(arr,temp,mid+1,right);
        
        count += merge(arr,temp,left,mid+1,right);
    }
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here. 
    long long temp[n];
    long long ans = mergesort(arr,temp,0,n-1);
    return ans;
}