#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int p = potions.size();
        sort(potions.begin(),potions.end());
        long long target;
        for(int i=0;i<spells.size();i++)
        {   
            target = (long long)(success/spells[i]);
            if(success%spells[i]!=0)
                target++;
            
            int index = lower_bound(potions.begin(),potions.end(),target) - potions.begin();
            
            ans.push_back(p-index);
        }
        return ans;
    }
};