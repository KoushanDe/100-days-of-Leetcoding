#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void parenRec(vector<string>& ans, string& paren,int& n,int count,int index)
    {
        if(index==n&&count==0)
        {
            ans.push_back(paren);
            return;
        }
        
        if(count==0)
        {   
            paren.push_back('(');
            parenRec(ans,paren,n,count+1,index+1);
            paren.pop_back();
        }
        else  {
            if(index<n){
            paren.push_back('(');
            parenRec(ans,paren,n,count+1,index+1);
            paren.pop_back();
            }
            paren.push_back(')');
            parenRec(ans,paren,n,count-1,index);
            paren.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string parentheses="";
        parenRec(ans,parentheses,n,0,0);
        
        return ans;
    }
};