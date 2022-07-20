class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        set<string> done;
        set<string> notdone;
        
        for(int i=0;i<words.size();i++)
        {   
            string temp = words[i];
            if(done.find(temp)!=done.end())
            {
                count++;
                continue;
            }
            if(notdone.find(temp)!=notdone.end())
                continue;
            
            int j=0,k=0;
            
            while(j<temp.size()&&k<s.size())
            {
                if(temp[j]==s[k])
                    j++,k++;
                else
                    k++;
            }
            
            if(j==temp.size())
            {
                done.insert(temp);
                count++;
            }
            else
                notdone.insert(temp);
        }
        
        return count;
    }
};