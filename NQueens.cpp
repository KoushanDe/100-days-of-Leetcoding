#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void nQueen(vector<string>& board, vector<vector<string>>& ans, int col,map<int,bool>& rowcheck, map<int,bool>& upperdiag, map<int,bool>& lowerdiag)
    {
        if(col==board.size())
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(rowcheck[i]==false&&lowerdiag[i+col]==false&&upperdiag[board.size()-1+col-i]==false)
            {
                board[i][col] = 'Q';
                rowcheck[i] = true;
                lowerdiag[i+col] = true;
                upperdiag[board.size()-1+col-i] = true;
                nQueen(board,ans,col+1,rowcheck,upperdiag,lowerdiag);
                
                board[i][col] = '.';
                rowcheck[i] = false;
                lowerdiag[i+col] = false;
                upperdiag[board.size()-1+col-i] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        map<int,bool> rowcheck;
        map<int,bool> upperdiag;
        map<int,bool> lowerdiag;
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        nQueen(board,ans,0,rowcheck,upperdiag,lowerdiag);
        return ans;
    }
};