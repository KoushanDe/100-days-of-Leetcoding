class Solution {
public:
    string reverseWords(string s) {
        
        while(s[0]==' ')
        {
            s.erase(s.begin());
        }
        
        while(s[s.size()-1]==' ')
        {
            s.erase(s.end()-1);
        }
        
        int start=0;
        int end=s.find(" ");
        
        while(end!=-1)
        {
            reverse(s.begin()+start,s.begin()+end);
            start = end+1;
            end = s.find(" ",start);
        }
        
        reverse(s.begin()+start,s.end());
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};