//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};
    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis,int n)
    {
        vis[i][j]=1;
        
        for(int d=0;d<4;d++)
        {
            int newi=i+di[d];
            int newj=j+dj[d];
            
            if(newi>=0&&newi<n&&newj>=0&&newj<n&&grid[newi][newj]!=0&&vis[newi][newj]==0)
            {
                if(grid[newi][newj]==2) return true;
                
                if(dfs(grid,newi,newj,vis,n))
                return true;
            }
        }
        
        return false;
        
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {   
        int n = grid.size();
        pair<int,int> src;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    src={i,j};
                    break;
                }
            }
        }
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        return dfs(grid,src.first,src.second,vis,n);
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends