#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> output;
        
        int index1=0,index2=numbers.size()-1;
        
        int sum=0;
        
        while(index1<index2)
        {
            sum = numbers[index1] + numbers[index2];
            
            if(sum<target)
            {
                index1++;
            }
            else if(sum>target)
            {
                index2--;
            }
            else
            {
                output.push_back(index1+1);
                output.push_back(index2+1);
                return output;
            }
        }
        
        return output;
        
    }
};