class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> unique;
        
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0;i<words.size();i++)
        {
            string temp="";
            for(int j=0;j<words[i].size();j++)
            {
                temp+=morse[words[i][j]-'a'];
            }
            unique.insert(temp);
        }
        
        return unique.size();
    }
};