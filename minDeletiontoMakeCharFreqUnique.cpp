#include<bits/stdc++.h>
using namespace std;
//OPTIMAL
class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        
        
        for(char c:s)
            v[c-'a']++;

        
        sort(v.begin(),v.end(),greater<int>());
        
        int maxAllow=s.size(),ans=0;
        
        for(auto f:v)
        {
            if(f<=maxAllow)
                maxAllow = f-1;
            else if(maxAllow>0)
            {
                ans = ans + f-maxAllow;
                maxAllow--;
            }
            else
                ans= ans+f;
        }
        return ans;
    }
};

//KIND OF BRUTE FORCE but good only solution
/*class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        
        map<int,char> mp;
        
        int count=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(count==0)
                count++;
            else
            {
                if(s[i]==s[i-1])
                    count++;
                else
                {
                    if(mp.find(count)==mp.end())
                        mp[count]=s[i-1];
                    else{
                        while(true)
                        {
                            count--;
                            ans++;
                            if(mp.find(count)==mp.end())
                            {
                                if(count>0)mp[count]=s[i-1];
                                break;
                            }
                        }
                    }
                    count=0;
                    i--;
                }
            }
        }
        
        int last = s.size()-1;
        if(mp.find(count)==mp.end())
            mp[count]=s[last];
        else{
            while(true)
            {
                count--;
                ans++;
                if(mp.find(count)==mp.end())
                {
                    if(count>0)mp[count]=s[last];
                    break;
                }
            }
        }
        
//         for(auto m:mp)
//             cout<<m.first<<" "<<m.second<<endl;
        
        
        
        return ans;
    }
};
*/