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
        unordered_map<string,int> chainlen;
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

//LIS APPROACH GIVING SIMILAR TIME COMPLEXITY
class Solution {
public:
    static bool isPossible(string& s1, string& s2)
    {
        if(s1.size()!=s2.size()+1)return false;
        
        int i=0,j=0;
        
        while(i<s1.size())
        {
            if(j<s2.size()&&s1[i]==s2[j])
                i++,j++;
            else
                i++;
        }
        if(i==s1.size()&&j==s2.size())return true;
        return false;
    }
    static bool compareSize(string& s1, string& s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1); 
        
        sort(words.begin(),words.end(),compareSize);
        
        int lsc=1;
        
        for(int ind=0;ind<n;ind++)
        {
            for(int pvind=0;pvind<ind;pvind++)
            {
                if(isPossible(words[ind],words[pvind])&&1+dp[pvind]>dp[ind])
                {
                    dp[ind] = 1+dp[pvind];
                }
                lsc = max(lsc,dp[ind]);
            }
        }
        
        return lsc;
    }
};