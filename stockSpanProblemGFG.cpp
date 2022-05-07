// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> st;
       vector<int> index;
       vector<int> ans;
       int i = 0;
       while(i<n)
       {
           if(st.empty())
           index.push_back(-1);
           else
           {
               if(price[st.top()]>price[i])
               {
                   index.push_back(st.top());
               }
               else
               {
                   st.pop();
                   continue;
               }
           }
           st.push(i);
           i++;
       }
       for(int j=0;j<index.size();j++)
       {
           ans.push_back(j-index[j]);
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends