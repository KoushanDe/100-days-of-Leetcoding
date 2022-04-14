#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    
    void findComb(string& digits,string& comb,vector<string>& ans,int index, map<char,string>& buttons)
    {
        if(index == digits.size())
        {
            ans.push_back(comb);
            return;
        }
            
            string chars = buttons[digits[index]];
            
            for(int j=0;j<chars.size();j++)
            {
                comb.push_back(chars[j]);
                findComb(digits,comb,ans,index+1,buttons);
                comb.pop_back();
            }
    }
        
    vector<string> letterCombinations(string digits) {
        map<char,string> buttons = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                    {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        vector<string> ans;
        string comb;
        
        if(digits == "")
            return ans;
        findComb(digits,comb,ans,0,buttons);
        return ans;
    }
};