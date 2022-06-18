#include<bits/stdc++.h>
using namespace std;
class WordFilter {
public:
    
    unordered_map<string,int> prefsuff;
    
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string word = words[i];
            
            for(int j=1;j<=word.size();j++)
            {
                string prefix = word.substr(0,j);
                
                for(int k=0;k<word.size();k++)
                {
                    string suffix = word.substr(k,word.size());
                    
                    prefsuff[prefix+"#"+suffix]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return prefsuff[prefix+"#"+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */