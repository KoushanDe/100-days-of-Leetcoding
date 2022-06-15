#include<bits/stdc++.h>
using namespace std;
/**MEMOISATION**
long func(long* values,int day,int buy,int size,vector<vector<long>>& dp)
{    
    if(day==size)
        return 0;
    
    if(dp[day][buy]!=-1) return dp[day][buy];
    long profit;
    if(buy)
    {
        profit = max(-values[day] + func(values,day+1,0,size,dp), 0 + func(values,day+1,1,size,dp));
    }
    else
    {
        profit = max(values[day]+func(values,day+1,1,size,dp),0+func(values,day+1,0,size,dp));
    }
    return dp[day][buy]=profit;
}*/
long getMaximumProfit(long *values, int n)
{    
    vector<long> ahead(2,0),curr(2,0);
    
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit;
            if(buy)
            {
                profit = max(-values[ind] + ahead[0], ahead[1]);
            }
            else
            {
                profit = max(values[ind]+ahead[1],ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead = curr;
    }
    
    return ahead[1];
}

/**GREEDY APPROACH**
long getMaximumProfit(long *values, int n)
{    
    long profit=0;
    for(int i=1;i<n;i++)
    {
        if(values[i]>values[i-1])
            profit+=(values[i]-values[i-1]);
    }
    return profit;
}*/