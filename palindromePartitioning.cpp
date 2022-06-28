#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s,int start, int end)
    {   
        while(start<=end)
        {
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }
    void f(string& s,int index,vector<string>& parts, vector<vector<string>>& ans)
    {
        if(index==s.size())
        {
            ans.push_back(parts);
            return;
        }
            
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                parts.push_back(s.substr(index,i-index+1));
                f(s,i+1,parts,ans);
                parts.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        
        f(s,0,parts,ans);
        return ans;
    }
};