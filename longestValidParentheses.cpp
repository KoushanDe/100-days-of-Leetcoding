#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> brackets;
        stack<int> index;
        
        index.push(-1);
        int maxlen = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                brackets.push('(');
                index.push(i);
            }
            else
            {
                if(!brackets.empty()&&brackets.top()=='(')
                {
                    brackets.pop();
                    index.pop();
                    maxlen = max(maxlen,i-index.top());
                }
                else
                {
                    index.push(i);
                }
            }
        }
        
        return maxlen;
    }
};