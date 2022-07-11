class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i=0;
        int n = s.size();
        
        while(i<n&&s[i]==' ')
            i++;
        
        if(s[i]=='-')
        {
            sign = 0;
            i++;
        }
        else if(s[i]=='+')
        {
            sign = 1;
            i++;
        }
        
        
        while(i<n&&s[i]>='0'&&s[i]<='9')
        {
                if(sign==1&&(num>INT_MAX/10||num==INT_MAX/10&&s[i]>='7'))
                   return INT_MAX;
                if(sign==0&&(num>INT_MAX/10||num==INT_MAX/10&&s[i]>='8'))
                   return INT_MIN;
                
                num = 10*num + (s[i] - '0') ;
            i++;
        }
      
        return sign?num:-num;
    }
};