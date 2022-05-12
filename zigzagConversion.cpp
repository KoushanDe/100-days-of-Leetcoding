#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        vector<string> temp(numRows,"");
        int row=0;
        int flag=0;
        if(numRows==1)
            return s;
        for(char c:s)
        {   
            temp[row]+=c;
            if(row==0)
                flag=0;
            if(row==numRows-1)
                flag=1;
            if(flag==0)
            row++;
            if(flag==1)
            row--;
                        
        }
        for(string i:temp)
        {
            ans+=i;
        }
        return ans;
    }
};