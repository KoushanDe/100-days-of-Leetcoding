#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& prices,int day,int buy,int fee,vector<vector<int>>& dp)
{    
    if(day>=prices.size())
        return 0;
    if(dp[day][buy]!=-1)return dp[day][buy];
    int profit;
    if(buy)
    {
        profit = max(-prices[day]+func(prices,day+1,0,fee,dp),func(prices,day+1,1,fee,dp));
    }
    else
    {
        profit = max(prices[day]-fee+func(prices,day+1,1,fee,dp),func(prices,day+1,0,fee,dp));
    }
    return dp[day][buy]=profit;
}*/
/**TABULATION**
 * int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    
    for(int day=n-1;day>=0;day--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit;
            if(buy)
            {
                profit = max(-prices[day]+dp[day+1][0],dp[day+1][1]);
            }
            else
            {
                profit = max(prices[day]-fee+dp[day+1][1],dp[day+1][0]);
            }
            dp[day][buy]=profit;
        }
    }
    return dp[0][1];
}
*/
/**SPACE OPTIMISATION**/
int maximumProfit(int n, int fee, vector<int> &prices) {
   vector<int> curr(2,0),after(2,0);
    
    for(int day=n-1;day>=0;day--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit;
            if(buy)
            {
                profit = max(-prices[day]+after[0],after[1]);
            }
            else
            {
                profit = max(prices[day]-fee+after[1],after[0]);
            }
            curr[buy]=profit;
        }
        after = curr;
    }
    return after[1];
}
