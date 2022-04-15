#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int minimumCost(int n, vector<int> x)
{	
	int odd=0,even=0;
	for(int i=0;i<n;i++)
	{
		if(x[i]%2==0)
			even++;
		else
			odd++;
	}
	if(even>odd)
		return odd;
	else
		return even;
}