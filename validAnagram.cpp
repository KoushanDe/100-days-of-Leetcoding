//TC=O(N) SC=O(26)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        vector<int> freq(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        
        for(int f:freq)
        {
            if(f!=0)
                return false;
        }
        
        return true;
    }
};

/*O(NLOGN)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        return s==t;
    }
};
*/