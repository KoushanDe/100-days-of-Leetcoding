#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string palindromesub(string &s,int i,int j)
    {
        int len = 0;
        while(i>=0&&j<s.size())
        {
            if(s[i]==s[j])
            {
                len = j-i+1;
                i--,j++;
            }
            else
                break;
        }
        return s.substr(i+1,len);
    }
    string longestPalindrome(string s) {
        int maxlen = 1;
        string ans="";
        string temp;
        ans+=s[0];
        for(int i=0;i<s.size();i++)
        {
            
            temp = palindromesub(s,i,i);
            
            if(temp.size()>maxlen)
            {
                maxlen = max(maxlen,(int)(temp.size()));
                ans = temp;
            }
            
            if(i<s.size()-1&&s[i]==s[i+1])
            {
                temp = palindromesub(s,i,i+1);
                if(temp.size()>maxlen)
                {
                    maxlen = max(maxlen,(int)(temp.size()));
                    ans = temp;
                }
            }
        }
        return ans;
    }
};