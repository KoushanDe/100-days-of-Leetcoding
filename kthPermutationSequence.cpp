#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void calcFacts(int n,vector<int>& factorials)
    {
        int f = 1;
        factorials.push_back(1);
        for(int i=1;i<=n;i++)
        {
            f=f*i;
            factorials.push_back(f);
        }
    }
        
    string getPermutation(int n, int k) {
        //pre calculate factorials 0 to n
        vector<int> factorials;
        calcFacts(n,factorials);
        
        string ans="";
        
        //stores numbers 1 to n
        vector<int> nums;
        
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        k=k-1; //to make 0 based index;
        
        while(n>1)
        {
            int ind = k/factorials[n-1];
            k = k%factorials[n-1];
            n--;
            
            ans += to_string(nums[ind]);
            nums.erase(nums.begin()+ind);
        }
        ans+=to_string(nums[0]);
        
        return ans;
    }
};