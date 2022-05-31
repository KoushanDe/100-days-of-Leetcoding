#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(k>s.size())return false;
        map<int,int> freq;
        int num=0;
        
        for(int i=0;i<k;i++)
        {
            num = num + (1<<(k-1-i))*(s[i]-'0');
        }
        freq[num]++;
        for(int i=1;i<=s.size()-k;i++)
        {   
            num = num*2;
            num -= (1<<k)*(s[i-1]-'0');
            num += s[i+k-1]-'0';
            freq[num]++;
        }
        
        for(int i=0;i<(1<<k);i++)
        {
            if(freq[i]==0)
                return false;
        }
        return true;
    }
};

/*
Very out of the box solution
Insert all substrings of size k in a set.
If we get all the codes the set should be of the size of 2^k (as the no of binary codes of size k is 2^k)

bool hasAllCodes(string s, int k) {
	
	//Edge case
	if(k > s.size()) return false;
    
    unordered_set<string> res_set;
    
	//Insertion into the set
    for(int i =0;i<= s.size()-k;i++)
        res_set.insert(s.substr(i,k));
    
	//Comparing res with 2^k
    return res_set.size() == pow(2,k);
}
/*