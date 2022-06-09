#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<vector<int>>& grid,int i,int j1, int j2,int n, int m,vector<vector<vector<int>>>& dp3)
{
    if(j1<0||j1>=m||j2<0||j2>=m) return -1e8 ;
    if(i==n-1)
    {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp3[i][j1][j2]!=-1)return dp3[i][j1][j2];
    int maxi = -1e8;
    
    for(int d1=-1;d1<=1;d1++)
    {
        for(int d2=-1;d2<=1;d2++)
        {    
            int val;
            if(j1==j2) val = grid[i][j1]+func(grid,i+1,j1+d1,j2+d2,n,m,dp3);
            else val = grid[i][j1]+grid[i][j2]+func(grid,i+1,j1+d1,j2+d2,n,m,dp3);
            maxi = max(val,maxi);
        }
    }
    return dp3[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp3(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return func(grid,0,0,c-1,r,c,dp3);
}*/

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp3(r,vector<vector<int>>(c,vector<int>(c,-1)));
    for(int i=r-1;i>=0;i--)
    {
        for(int j1=0;j1<c;j1++)
        {
            for(int j2=0;j2<c;j2++)
            {
                if(i==r-1)
                {
                    if(j1==j2) dp3[i][j1][j2]=grid[i][j1];
                    else dp3[i][j1][j2]=grid[i][j1]+grid[i][j2];
                }
                else
                {
                    int maxi = -1e8;
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {    
                            if(j1+d1>=0&&j1+d1<c&&j2+d2>=0&&j2+d2<c)
                            {
                                int val;
                                if(j1==j2) val = grid[i][j1]+dp3[i+1][j1+d1][j2+d2];
                                else val = grid[i][j1]+grid[i][j2]+dp3[i+1][j1+d1][j2+d2];
                                maxi = max(val,maxi);
                            }
                        }
                    }
                    dp3[i][j1][j2] = maxi;
                }
            }
        }
    }
    return dp3[0][0][c-1];
}

