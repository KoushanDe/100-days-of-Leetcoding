#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    static bool sortWords(string& s1, string& s2)
    {
        return s1.size()>s2.size();
    }
    
    
    int maxProduct(vector<string>& words) {
        int output=0,flag;
        
        sort(words.begin(),words.end(),sortWords);
       
        vector<map<char,int>> wordmap(words.size());
        
        for(int i=0;i<words.size();i++)
        {
            for(char chr: words[i])
                wordmap[i][chr]++;
        }
        
        for(int i=0;words[i].size()>sqrt(output)&&i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {   
                flag=0;
                for(char k='a';k<='z';k++)
                {   
                    if(wordmap[i][k]!=0&&wordmap[j][k]!=0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {   
                    int product = words[i].length()*words[j].length();
                    output = max(output,product);
                    break;   
                }
            }
        }
        
        return output;
    }
};