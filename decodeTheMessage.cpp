class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> cipher;
        
        char ch = 'a';
        
        for(char c:key)
        {   
            if(c==' ')
                continue;
            else if(cipher[c]==0)
                cipher[c]=ch++;
        }
        
        string ans="";
        
        for(char m:message)
        {   
            if(m!=' ')
                ans = ans + cipher[m];
            else
                ans = ans + " ";
        }
        
        return ans;
    }
};