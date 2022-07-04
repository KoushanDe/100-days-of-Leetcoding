#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool compareRating(pair<int,int>& p1,pair<int,int>& p2)
    {
        return p1.first<p2.first;
    }
    int candy(vector<int>& ratings) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<ratings.size();i++)
        {
            v.push_back({ratings[i],i});
        }
        
        vector<int> candies(ratings.size(),0);
        
        sort(v.begin(),v.end(),compareRating);
        
        int sum=0;
        
        for(auto p:v)
        {
            int rating = p.first;
            int index = p.second;
            
            int left = index==0?INT_MAX:ratings[index-1];
            int right = index==ratings.size()-1?INT_MAX:ratings[index+1];
            
            if(rating<=left&&rating<=right)
                candies[index]=1;
            else
            {
                if(rating>left)
                    candies[index] = candies[index-1]+1;
                if(rating>right)
                    candies[index] = max(candies[index],candies[index+1]+1);
            }
            
            sum+=candies[index];
        }
        
        return sum;
    }
};