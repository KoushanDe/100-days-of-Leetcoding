#include<bits/stdc++.h>

using namespace std;
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
	int n = nums.size()-1;
	int dp[n+1];
	dp[0] = nums[0];
	for(int i=1;i<=n;i++)
	{
		int nopick = dp[i-1];
		int pick = INT_MIN;
		if(i>1)
			pick = nums[i] + dp[i-2];
		else
			pick = nums[i];
		dp[i] = max(pick,nopick);
	}
	return dp[n];
}