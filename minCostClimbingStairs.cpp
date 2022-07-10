class Solution {
public:
    /**MEMOISATION**
    int f(vector<int>& cost, int index,vector<int>& dp)
    {   
        if(index>=cost.size())
            return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        int onestep = cost[index] + f(cost,index+1,dp);
        int twostep = cost[index] + f(cost,index+2,dp);
        
        return dp[index]=min(onestep,twostep);
    }
    **
    **TABULATION**
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,0);
        
        //dp[n]=dp[n+1]=0; base case, but already inisialised
        
        for(int index=n-1;index>=0;index--)
        {
            int onestep = cost[index] + dp[index+1];
            int twostep = cost[index] + dp[index+2];

            dp[index]=min(onestep,twostep);
        }
        return min(dp[0],dp[1]);
    }*/
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int twostepdp=0,onestepdp=0,curr=0;
        
        for(int index=n-1;index>=0;index--)
        {
            int onestep = cost[index] + onestepdp;
            int twostep = cost[index] + twostepdp;

            curr=min(onestep,twostep);
            twostepdp = onestepdp;
            onestepdp = curr;
        }
        return min(onestepdp,twostepdp);
    }
};