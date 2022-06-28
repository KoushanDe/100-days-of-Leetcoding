// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<int> di={-1,1,0,0};
    vector<int> dj={0,0,-1,1};
    vector<char> dir={'U','D','L','R'};
    
    bool isPossible(vector<vector<int>> cells,vector<vector<int>>& vis,int row, int col)
    {
        int n = cells.size();
        
        if(row>=0&&row<n&&col>=0&&col<n&&cells[row][col]==1&&vis[row][col]==0)
            return true;
        return false;
    }
    
    void f(int i,int j,vector<vector<int>>& cells,int n,string& path, vector<string>& ans,
    vector<vector<int>>& vis)
    {
        if(i==n-1&&j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        for(int k=0;k<4;k++)
        {
            if(isPossible(cells,vis,i+di[k],j+dj[k]))
            {
                path.push_back(dir[k]);
                vis[i+di[k]][j+dj[k]]=1;
                f(i+di[k],j+dj[k],cells,n,path,ans,vis);
                path.pop_back();
                vis[i+di[k]][j+dj[k]]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string path;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==0)return ans;
        vis[0][0]=1;
        
        f(0,0,m,n,path,ans,vis);
        
        return ans;
    }
};
