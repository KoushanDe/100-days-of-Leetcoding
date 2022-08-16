class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> ind;
        
        for(int i=0;i<s.size();i++)
        {
            if(ind.find(s[i])==ind.end())
                ind[s[i]]=i;
            else
                ind[s[i]]=-1;
        }
        int minm=INT_MAX;
        for(auto m:ind)
        {
            if(m.second!=-1)
                minm=min(minm,m.second);
        }
        
        return minm==INT_MAX?-1:minm;
    }
};