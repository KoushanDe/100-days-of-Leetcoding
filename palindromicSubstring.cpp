#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i=0;i<s.size();i++)
        {
            count++;
            
            for(int j=i-1,k=i+1;j>=0,k<s.size();j--,k++)
            {
                if(j>=0&&k<s.size()&&s[j]==s[k])
                count++;
                else
                    break;
            }
            
            for(int j=i,k=i+1;j>=0,k<s.size();j--,k++)
            {
                if(j>=0&&k<s.size()&&s[j]==s[k])
                count++;
                else
                    break;
            }
        }
        
        return count;
    }
};