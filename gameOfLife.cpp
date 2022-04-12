#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int di[8] = {-1,-1,0,1,1,1,0,-1};
        int dj[8] = {0,1,1,1,0,-1,-1,-1};
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    if(i+di[k]>=0&&i+di[k]<m&&j+dj[k]>=0&&j+dj[k]<n)
                    {
                        if(board[i+di[k]][j+dj[k]]==1||board[i+di[k]][j+dj[k]]==-1)
                            count++;
                    }
                }
                
                if(count<2)
                {
                    if(board[i][j]==1)
                        board[i][j]=-1;
                }
                else if(count==3)
                {
                    if(board[i][j]==0)
                        board[i][j]=2;
                }
                else if(count>3)
                {
                    if(board[i][j]==1)
                        board[i][j]=-1;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(board[i][j]==-1)
                    board[i][j]=0;
                else if(board[i][j]==2)
                    board[i][j]=1;
            }
        }
    }
};