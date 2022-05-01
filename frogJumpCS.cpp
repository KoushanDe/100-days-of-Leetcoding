#include<bits/stdc++.h>

using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	int dp[n];
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<n;i++)
	{
		int left = (abs)(heights[i]-heights[i-1]) + dp[i-1];
		int right = INT_MAX;
		if(i>1)
			right = (abs)(heights[i]-heights[i-2]) + dp[i-2];
		dp[i]=min(left,right);
	}
	return dp[n-1];
}