#include<bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount) 
{
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    
    int total=0;
    int ind = 8;
    while(amount>0)
    {
        if(amount/coins[ind]>0)
        {
            total++;
            amount -= (coins[ind]);
        }
        else
            ind--;
    }
    
    return total;
}
