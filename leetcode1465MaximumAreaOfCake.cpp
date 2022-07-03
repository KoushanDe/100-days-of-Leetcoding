int mod = (int)(1e9+7);

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxVertical=verticalCuts[0],maxHorizontal=horizontalCuts[0];
        
        
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(w);
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            if(horizontalCuts[i]-horizontalCuts[i-1]>maxHorizontal)
                maxHorizontal=horizontalCuts[i]-horizontalCuts[i-1];
        }
        
        for(int i=1;i<verticalCuts.size();i++)
        {
            if(verticalCuts[i]-verticalCuts[i-1]>maxVertical)
                maxVertical=verticalCuts[i]-verticalCuts[i-1];
        }
        
        
        return (1LL*maxVertical*maxHorizontal)%mod; //trick to do multiplicative mod
    }
};