class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int sum=0;
        bool isNeg = x<0;
        x = abs(x);
        while(x)
        {   
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&x>8))return 0; //INT_MAX=2147483647
            if(sum==INT_MAX/10&&x==8) return INT_MIN;
            sum = sum*10 + x%10;
            x=x/10;
        }
        
        return isNeg?-sum:sum;
    }
};