#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& prices,int day,int buy,vector<vector<int>>& dp)
{    
    if(day>=prices.size())
        return 0;
    if(dp[day][buy]!=-1)return dp[day][buy];
    int profit;
    if(buy)
    {
        profit = max(-prices[day]+func(prices,day+1,0,dp),func(prices,day+1,1,dp));
    }
    else
    {
        profit = max(prices[day]+func(prices,day+2,1,dp),func(prices,day+1,0,dp));
    }
    return dp[day][buy]=profit;
}*/
/**TABULATION**
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    
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
                profit = max(prices[day]+dp[day+2][1],dp[day+1][0]);
            }
            dp[day][buy]=profit;
        }
    }
    
    return dp[0][1];
}*/
/**SPACE OPTIMISED**/
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> curr(2,0),nextday(2,0),nexttonext(2,0);
    
    for(int day=n-1;day>=0;day--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit;
            if(buy)
            {
                profit = max(-prices[day]+nextday[0],nextday[1]);
            }
            else
            {
                profit = max(prices[day]+nexttonext[1],nextday[0]);
            }
            curr[buy]=profit;
        }
        nexttonext = nextday;
        nextday = curr;
    }
    
    return nextday[1];
}