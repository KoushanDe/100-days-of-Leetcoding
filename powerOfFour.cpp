class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int x = log(n) /log(4) ;
        return pow(4, x) ==n;
    }
};