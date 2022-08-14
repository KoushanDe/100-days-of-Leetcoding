//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int> dist(31,INT_MAX);
        dist[1]=0;
        map<int,int> snkeOrladr;
        
        for(int i=0;i<2*N;i+=2)
        {
            snkeOrladr[arr[i]]=arr[i+1];
        }
        
        queue<int> q;
        q.push(1);
        
        while(!q.empty())
        {
            int cell = q.front();
            q.pop();
            
            for(int x=1;x<=6;x++)
            {
                int newcell=cell+x;
                if(newcell>30) break;
                
                if(snkeOrladr[newcell]!=0)
                newcell=snkeOrladr[newcell];
                
                if(1+dist[cell]<dist[newcell])
                {
                    dist[newcell]=1+dist[cell];
                    if(newcell==30) return dist[30];
                    //cout<<newcell<<" ";
                    q.push(newcell);
                }
            }
        }
        
        return dist[30];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends