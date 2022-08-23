#include <iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> freq;
bool compareFreq(int& n1, int& n2)
  {
      if(freq[n1]==freq[n2])
      return n1<n2;
      
      return freq[n1]>freq[n2];
  }

int main() {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    //Solution S;
	    
	    vector<int> ans;
	    
	    for(int i=0;i<n;i++)
	    {
	        int num;
	        cin>>num;
	        freq[num]++;
            ans.push_back(num);
	    }
	    
	    sort(ans.begin(),ans.end(),compareFreq);
	    
	    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
      
        cout<<endl;
        
        freq.clear();
	}
	return 0;
}