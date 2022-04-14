#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col, char val)
    {   
        int boxrow = (row/3)*3;
        int boxcol = (col/3)*3;
        
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]==val)
                return false;
            if(board[row][i]==val)
                return false;
        }
        for(int i=boxrow;i<boxrow+3;i++)
        {
            for(int j=boxcol;j<boxcol+3;j++)
            {
                if(board[i][j]==val)
                    return false;
            }
        }
        
        return true;
    }
    
    bool sudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            
                            if(sudoku(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};