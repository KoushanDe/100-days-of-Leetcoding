class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int i=1;
        
        if(n>1)
        {
            s="11";
            i++;
        }
        
        while(i<n)
        {   
            char prev=s[0];
            int count=1;
            string temp="";
            for(int j=1;j<s.size();j++)
            {   
                if(s[j]!=prev&&count!=0)
                {
                    temp = temp + to_string(count) + prev;
                    prev=s[j];
                    count=1;
                }
                else if(s[j]==prev)
                    count++;
            }
            temp = temp + to_string(count) + prev;
            s=temp;
            i++;
        }
        
        return s;
    }
};