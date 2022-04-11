#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void nQueen2(vector<string>& board, int& ans, int col,map<int,bool>& rowcheck, map<int,bool>& upperdiag, map<int,bool>& lowerdiag)
    {
        if(col==board.size())
        {
            ans++;
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
                nQueen2(board,ans,col+1,rowcheck,upperdiag,lowerdiag);
                
                board[i][col] = '.';
                rowcheck[i] = false;
                lowerdiag[i+col] = false;
                upperdiag[board.size()-1+col-i] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');
        
        map<int,bool> rowcheck;
        map<int,bool> upperdiag;
        map<int,bool> lowerdiag;
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        nQueen2(board,ans,0,rowcheck,upperdiag,lowerdiag);
        return ans;
    }
};