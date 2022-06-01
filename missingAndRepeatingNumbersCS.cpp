#include <bits/stdc++.h> 
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	sort(arr.begin(),arr.end());
    pair<int,int> ans;
    int flag=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==arr[i-1])
        {
            ans.second=arr[i];
            arr.erase(arr.begin()+i);
            i--;
        }
        else if(arr[i]!=i+1&&flag==0)
        {
            ans.first=i+1;
            flag=1;
        }
    }
    
    if(ans.first==0)ans.first=n;
    
    return ans;
}
