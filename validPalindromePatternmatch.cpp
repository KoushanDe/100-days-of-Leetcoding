#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int c=0;
        while(i<j)
        {   
            if(s[i]==s[j])
            {
                i++,j--;
            }
            else
            {
                if(c==0)
                {
                    c=1;
                    if(i==j-1)
                    {
                        return true;
                    }
                    if(s.size()<=5)
                    {
                            if(s[i+1]==s[j])
                        {
                            i+=2;
                            j--;
                        }
                        else if(s[i]==s[j-1])
                        {
                            j-=2;
                            i++;
                        }
                        else
                            return false;
                    }
                    else if(s.size()==6)
                    {
                        if(s[i+1]==s[j]&&s[i+2]==s[j-1])
                    {
                        i++;
                    }
                    else if(s[i]==s[j-1]&&s[i+1]==s[j-2])
                    {
                        j--;
                    }
                    else
                        return false;
                    }
                    else{
                    if(s[i+1]==s[j]&&s[i+2]==s[j-1]&&s[i+3]==s[j-2])
                    {
                        i++;
                    }
                    else if(s[i]==s[j-1]&&s[i+1]==s[j-2]&&s[i+2]==s[j-3])
                    {
                        j--;
                    }
                    else
                        return false;
                    }
                }
                else
                    return false;
            }
        }
        return true;
    }
};