class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        
        int a=0,b=1;
        
        for(int i=2;i<=n;i++)
        {
            b=a+b;
            a=b-a;
        }
        
        return b;
    }
};

/*RECURSIVE*
class Solution {
public:
    int fib(int n) {
        if(n==0||n==1) return n;
        return fib(n-1)+fib(n-2);
    }
};
**
Tabulation dp
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        vector<int> fibo(n+1);
        
        fibo[0]=0;
        fibo[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            fibo[i] = fibo[i-1]+fibo[i-2];
        }
        
        return fibo[n];
    }
};
*/