#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        
        vector<vector<string>> ans;
        int ind1 = 0;
        int ind2;
        
        for(int i=products.size()-1;i>=0;i--)
        {
            if(products[i][0]==searchWord[0])
            {
                ind2=i;
                break;
            }
        }
        string word="";
        int flag;
        for(int i=0;i<searchWord.size();i++)
        {
            vector<string> temp;
            word+=searchWord[i];
            flag=0;
            
            for(int j = ind1;j<=ind2&&temp.size()<3; j++)
            {
                if(i<products[j].size()&&products[j].substr(0,i+1)==word)
                {
                    temp.push_back(products[j]);
                    if(flag==0)
                    {
                        ind1=j;
                        flag=1;
                    }
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};