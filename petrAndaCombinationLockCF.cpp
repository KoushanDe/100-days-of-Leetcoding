#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool f(vector<int>& rotations,int index, int total)
{
	if(index==rotations.size())
	{
		return (total%360)==0;
	}

	if(f(rotations,index+1,total+rotations[index])==true)
	return true;

	if(f(rotations,index+1,total-rotations[index])==true)
	return true;

	return false;
}

int main() {
	int n;
	vector<int> rotations;

	cin>>n;

	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		rotations.push_back(r);
	}

	if(f(rotations,0,0)==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}