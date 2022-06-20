#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(),words[i].end());
        }
        
        sort(words.begin(),words.end());
        
        int len = words[0].size()+1;
        
        for(int i=1;i<words.size();i++)
        {   
            if(words[i].substr(0,words[i-1].size())==words[i-1])
            {
                len+=(words[i].size()-words[i-1].size());
            }
            else
                len+= (words[i].size()+1);
        }
        
        return len;
    }
};