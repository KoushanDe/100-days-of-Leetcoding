#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        int upchar=0,lochar=0,dig=0,spchar=0,len=0;
        
        for(int i=0;i<pass.size();i++)
        {   
            len++;
            if(pass[i]>='A'&&pass[i]<='Z')upchar++;
            else if(pass[i]>='a'&&pass[i]<='z')lochar++;
            else if(pass[i]>='0'&&pass[i]<='9')dig++;
            else if(pass[i]=='!'||pass[i]=='@'||pass[i]=='#'||pass[i]=='$'||pass[i]=='%'||pass[i]=='^'||pass[i]=='&'||pass[i]=='*'||pass[i]=='('||pass[i]==')'||pass[i]=='-'||pass[i]=='+')spchar++;
            
            if(i+1<pass.size()&&pass[i]==pass[i+1]) return false;
        }
        
        if(upchar>0&&lochar>0&&dig>0&&spchar>0&&len>=8) return true;
        return false;
    }
};