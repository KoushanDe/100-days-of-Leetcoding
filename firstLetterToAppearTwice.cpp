class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> ch(26,0);
        
        for(char c:s)
        {
            if(ch[c-'a']>0)
                return c;
            else
                ch[c-'a']++;
        }
        
        return 0;
    }
};