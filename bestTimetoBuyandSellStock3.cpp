#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
int func(vector<int>& values,int day,int buy,int tleft,vector<vector<vector<int>>>& dp)
{    
    if(day==values.size())
        return 0;
    if(tleft==0)
        return 0;
    
    if(dp[day][buy][tleft]!=-1) return dp[day][buy][tleft];
    int profit;
    if(buy)
    {
        profit = max(-values[day] + func(values,day+1,0,tleft,dp), 0 + func(values,day+1,1,tleft,dp));
    }
    else
    {
        profit = max(values[day]+func(values,day+1,1,tleft-1,dp),0+func(values,day+1,0,tleft,dp));
    }
    return dp[day][buy][tleft]=profit;
}*/
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    
    //can omit base cases because dp already initialised with 0,
    //just need to determine starting values of loops
    
    for(int day = n-1;day>=0;day--)
    {
        for(int buy = 0;buy<=1;buy++)
        {
            for(int tleft=1;tleft<=2;tleft++)
            {
                int profit;
                if(buy)
                {
                    profit = max(-prices[day] + dp[day+1][0][tleft], dp[day+1][1][tleft]);
                }
                else
                {
                    profit = max(prices[day]+dp[day+1][1][tleft-1],dp[day+1][0][tleft]);
                }
                dp[day][buy][tleft]=profit;
            }
        }
    }
   
    return dp[0][1][2];
}