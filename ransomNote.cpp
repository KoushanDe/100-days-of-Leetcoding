class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        
        for(char c:magazine)
            freq[c-'a']++;
        
        for(char r:ransomNote)
        {
            if(freq[r-'a']==0) return false;
            freq[r-'a']--;
        }
        
        return true;
    }
};