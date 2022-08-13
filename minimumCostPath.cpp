//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int di[4] = {-1,0,1,0};
        int dj[4] = {0,1,0,-1};
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            for(int d=0;d<4;d++)
            {
                int newi=i+di[d];
                int newj=j+dj[d];
                
                if(newi>=0&&newi<n&&newj>=0&&newj<n&&dist[newi][newj]>dist[i][j]+grid[newi][newj])
                {
                    dist[newi][newj] = dist[i][j]+grid[newi][newj];
                    pq.push({dist[newi][newj],{newi,newj}});
                }
            }
        }
        
        return dist[n-1][n-1];
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends