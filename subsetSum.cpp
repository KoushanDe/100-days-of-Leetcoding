// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    void printSum(vector<int>& arr, int index, vector<int>& ans,int sum)
    {
        if(index<0)
        {
            ans.push_back(sum);
            return;
        }
        
        printSum(arr,index-1,ans,sum);
        printSum(arr,index-1,ans,sum+arr[index]);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        
        printSum(arr,N-1,ans,0);
        return ans;
    }
};
