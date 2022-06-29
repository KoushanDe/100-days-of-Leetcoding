#include<bits/stdc++.h>
#include<iostream>
class Solution {
public:
    static bool compareV(vector<int>& v1, vector<int>& v2)
    {
        if(v1[0]>v2[0]) return true;
        else if(v1[0]==v2[0])
            return v1[1]<v2[1];
        else
            return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compareV);
        
        vector<vector<int>> ans;
        
        //khatay dry run karo sab samajh me aa jayega
        for(int i=0;i<people.size();i++)
        {
            if(i==people[i][1])
                ans.push_back(people[i]);
            else
            {
                ans.insert(ans.begin()+people[i][1],people[i]);
            }
        }
        
        return ans;
        
    }
};