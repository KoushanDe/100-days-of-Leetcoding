#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(string st)
    {   
        int i=0,j=st.size()-1;
        while(i<j)
        {
            if(st[i]!=st[j])
                return false;
            i++,j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return(isPalindrome(s.substr(i,j-i))||isPalindrome(s.substr(i+1,j-i)));
            }
            i++,j--;
        }
        return true;
    }
};