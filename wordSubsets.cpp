class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        
        for(int i=0;i<words2.size();i++)
        {
            vector<int> temp(26,0);
            for(int j=0;j<words2[i].size();j++)
            {
                temp[words2[i][j]-'a']++;
                freq[words2[i][j]-'a'] = max(freq[words2[i][j]-'a'],temp[words2[i][j]-'a']);
            }
        }
        
        vector<string> ans;
        
        for(int i=0;i<words1.size();i++)
        {
            vector<int> temp(26,0);
            for(int j=0;j<words1[i].size();j++)
                temp[words1[i][j]-'a']++;
            
            int flag=0;
            for(int ch = 0;ch<26;ch++)
            {
                if(temp[ch]<freq[ch])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};