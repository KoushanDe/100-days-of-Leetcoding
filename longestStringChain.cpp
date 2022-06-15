#include<bits/stdc++.h>
using namespace std;
//MY CODE
class Solution {
public:
    static bool compareSize(string& s1, string& s2)
    {
        return s1.size()>s2.size();
    }
    int longestStrChain(vector<string>& words) {
        map<string,int> chainlen;
        int maxlen = 1;
        for(string word:words)
            chainlen[word] = 1;
        sort(words.begin(),words.end(),compareSize);
        
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                string temp = words[i];
                temp.erase(temp.begin()+j);
                if(chainlen[temp]!=0)
                {
                    chainlen[temp] = chainlen[words[i]]+1;
                    maxlen = max(maxlen,chainlen[temp]);
                }
            }
        }
        return maxlen;
    }
};