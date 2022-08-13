//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[X][Y]==0||A[0][0]==0) return -1;
        // code here
        vector<vector<int>> dist(N,vector<int>(M,INT_MAX));
        dist[0][0]=0;
        
        
        int di[4] = {-1,0,1,0};
        int dj[4] = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();
            
            if(i==X&&j==Y)
            return dist[X][Y];
            
            for(int d=0;d<4;d++)
            {
                int newi=i+di[d];
                int newj=j+dj[d];
                
                if(newi>=0&&newi<N&&newj>=0&&newj<M&&A[newi][newj]==1&&dist[newi][newj]>dist[i][j]+1)
                {
                    dist[newi][newj]=1+dist[i][j];
                    q.push({newi,newj});
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends