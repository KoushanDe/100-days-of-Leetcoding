#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int max_area = INT_MIN;
        
        while(i<j)
        {
            max_area=max(max_area,min(height[i],height[j])*(j-i));
            if(min(height[i],height[j])==height[i])
            {   
                int temp = height[i];
                while(height[i]<=temp&&i<j)
                    i++;
            }
            else
            {
                int temp = height[j];
                while(height[j]<=temp&&i<j)
                    j--;
            }
        }
        return max_area;
    }
};