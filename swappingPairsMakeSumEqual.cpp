//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int isSwap(int A[], int n, int B[], int m, int target)
	{   
	    if(target&1)
	    return -1;
	    
	    int i=0,j=0;
	    
	    while(i<n&&j<m)
	    {
	        if(B[j]-A[i]==target/2)
	        return 1;
	        else if(B[j]-A[i]>target/2)
	        i++;
	        else
	        j++;
	    }
	    
	    return -1;
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        sort(A,A+n);
        sort(B,B+m);
        
        int sum1 = accumulate(A,A+n,0);
        int sum2 = accumulate(B,B+m,0);
        
        if(sum2>sum1)
        return isSwap(A,n,B,m,sum2-sum1);
        else
        return isSwap(B,m,A,n,sum1-sum2);
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends