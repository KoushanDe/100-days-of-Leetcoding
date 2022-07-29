class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.size();
        
        for(int i=0;i<words.size();i++)
        {   
            int m = words[i].size();
            if(n==m)
            {
                map<char,char> word_pattern;
                map<char,char> pattern_word;
                int flag=0;
                
                for(int j=0;j<m;j++)
                {
                    if(word_pattern[words[i][j]]==NULL&&pattern_word[pattern[j]]==NULL)
                    {
                        word_pattern[words[i][j]]=pattern[j];
                        pattern_word[pattern[j]]=words[i][j];
                    }
                    else if(word_pattern[words[i][j]]!=pattern[j]||pattern_word[pattern[j]]!=words[i][j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    ans.push_back(words[i]);
            }
        }
        return ans;
    }
};