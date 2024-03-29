//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    map<int,int> index;
	    for(int i=0;i<nums.size();i++)
	    {
	        index[nums[i]]=i;
	    }
	    vector<int> temp;
	    temp=nums;
	    sort(temp.begin(),temp.end());
	    int swaps=0;
	    for(int i=0;i<nums.size();i++)
	    {   
	        int num = nums[i];
	        int t = index[temp[i]];
	        if(nums[i]!=temp[i])
	        {
	            swap(nums[i],nums[t]);
	            swaps++;
	        
	        index[temp[i]]=i;
	        index[num] = t;
	        }
	    }
	    
	    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends