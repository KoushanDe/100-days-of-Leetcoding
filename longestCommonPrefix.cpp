class Solution {
public:
    static bool compareSize(string& s1,string& s2)
    {
        return s1.size()<s2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),compareSize);
        
        string s = strs[0];
        int n = s.size();
        if(n==0)
            return "";
        
        for(int i=n;i>=1;i--)
        {   
            string temp = s.substr(0,i);
            int flag=1;
            for(int j=1;j<strs.size();j++)
            {
                if(temp!=strs[j].substr(0,i))
                {
                    flag=0;
                    break;
                }
            }
            
            if(flag==1)
                return temp;
        }
        
        return "";
    }
};

//Better Brute approach
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;
        
        while(true)
        {   
            int flag=0;
            if(index>=strs[0].size()) break;
            
            char c = strs[0][index];
            
            for(int i=1;i<strs.size();i++)
            {
                if(index>=strs[i].size()||strs[i][index]!=c)
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
                index++;
            else
                break;
        }
        
        return strs[0].substr(0,index);
        
    }
};