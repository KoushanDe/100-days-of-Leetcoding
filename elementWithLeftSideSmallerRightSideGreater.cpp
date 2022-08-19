//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    
    vector<int> leftbig(n),rightsmall(n);
    
    int maxm=-1;
    leftbig[0]=-1;
    for(int i=1;i<n;i++)
    {
        maxm=max(maxm,arr[i-1]);
        leftbig[i]=maxm;
    }
    int minm=INT_MAX;
    rightsmall[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        minm=min(minm,arr[i+1]);
        rightsmall[i]=minm;
    }
    
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>=leftbig[i]&&arr[i]<=rightsmall[i])
        return arr[i];
    }
    
    return -1;
}