#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& positions, int mid,int c)
{	
	int prev = positions[0];
    int count=1;
	for(int i=1;i<positions.size();i++)
	{
		if(positions[i]-prev>=mid)
		{
			prev=positions[i];
			count++;
		}
        if(count==c) return true;
	}
	
	return false;
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{   
        int n,c;
		cin>>n>>c;
		
		vector<int> positions;
		
		for(int i=0;i<n;i++)
		{	
			int pos;
			cin>>pos;
			positions.push_back(pos);
		}
		
		sort(positions.begin(),positions.end());
		
		int low = 1, high = positions[n-1]-positions[0];
		int ans=0;
		
		while(low<=high)
		{
			int mid = (low+high)/2;
			
			if(isPossible(positions,mid,c))
			{	
				ans=mid;
				low=mid+1;
			}
			else
			{
				high = mid-1;
			}
		}
		
		cout<<ans;
	}
	return 0;
}