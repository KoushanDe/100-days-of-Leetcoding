#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> rec;
        int sum=0;
        
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {   
                sum-=rec.back();
                rec.pop_back();
            }
            else if(ops[i]=="D")
            {   
                sum+=rec.back()*2;
                rec.push_back(rec.back()*2);
            }
            else if(ops[i]=="+")
            {   
                int add = rec.at(rec.size()-1)+rec.at(rec.size()-2);
                sum+=add;
                rec.push_back(add);
            }
            else
            {
                rec.push_back(stoi(ops[i]));
                sum+=rec.back();
            }
        }
        
        return sum;
    }
};