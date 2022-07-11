class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> numbers;
        
        numbers["I"] = 1;
        numbers["IV"] = 4;
        numbers["V"] = 5;
        numbers["IX"] = 9;
        numbers["X"] = 10;
        numbers["XL"] = 40;
        numbers["L"] = 50;
        numbers["XC"] = 90;
        numbers["C"] = 100;
        numbers["CD"] = 400;
        numbers["D"] = 500;
        numbers["CM"] = 900;
        numbers["M"] = 1000;
        
        int i=0;
        int num=0;
        while(i<s.size())
        {   
            string temp = "";
            
            if(i+1<s.size())
                temp = temp + s[i] + s[i+1];
            
            if(numbers[temp]!=0)
            {   
                num += numbers[temp];
                i+=2;
            }
            else
            {   
                temp="";
                temp += s[i];
                num += numbers[temp];
                i++;
            }
        }
        
        return num;
        
    }
};