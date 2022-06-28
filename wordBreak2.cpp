#include<bits/stdc++.h>
using namespace std;
void findWords(string& s,int index,unordered_set<string>& dict,vector<string>& ans)
{
    if(index==s.size()-1)
    {    
        int start = 0;
        int end = s.find(" ");
        while (end != -1) {
            if(dict.find(s.substr(start, end - start))==dict.end()) return;
            start = end + 1;
            end = s.find(" ", start);
        }
        if(dict.find(s.substr(start, end - start))==dict.end()) return;
         
        ans.push_back(s);
        return;   
    }
    
    s.insert(index+1," ");
    findWords(s,index+2,dict,ans);
    s.erase(s.begin()+index+1);
    findWords(s,index+1,dict,ans);
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    unordered_set<string> dict;
    
    for(string str:dictionary)
        dict.insert(str);
    findWords(s,0,dict,ans);
    
    return ans;
}