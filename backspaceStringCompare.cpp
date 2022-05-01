#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sS;
        stack<char> tS;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
                sS.push(s[i]);
            else if(!sS.empty())
                sS.pop();
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!='#')
                tS.push(t[i]);
            else if(!tS.empty())
                tS.pop();
        }
        
        while(!sS.empty()&&!tS.empty())
        {
            if(sS.top()!=tS.top())
                return false;
            sS.pop();
            tS.pop();
        }
        
        if(!sS.empty()||!tS.empty())
            return false;
        return true;
    }
};