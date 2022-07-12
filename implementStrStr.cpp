//BRUTE
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for(int i=0;i<haystack.size();i++)
        {
            if(needle[0]==haystack[i])
            {
                int flag=1;
                int j=i+1;
                while(j-i<needle.size())
                {
                    if(needle[j-i]!=haystack[j])
                    {
                        flag=0;
                        break;
                    }
                    j++;
                }
                if(flag==1)
                    return i;
            }
        }
        
        return -1;
    }
};