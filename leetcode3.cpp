#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> freq;
        int i=0,j=0;
        int count=0;
        while(i<s.size()&&j<s.size())
        {
            if(freq[s[i]]==0)
            {   
                freq[s[i]]++;
                i++;
                count=max(count,i-j);
            }
            else
            {   
                freq[s[j]]--;
                j++;
            }
        }
        
        return count;
    }
};