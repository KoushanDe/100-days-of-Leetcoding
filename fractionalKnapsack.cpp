#include<bits/stdc++.h>
using namespace std;
bool compareValues(pair<int,int>& i1,pair<int,int>& i2)
{
    double v1 = double(i1.second)/double(i1.first);
    double v2 = double(i2.second)/double(i2.first);
    
    return v1>v2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),compareValues);
    double profit=0;
    for(int i=0;i<n;i++)
    {
        if(w>=items[i].first)
        {
            w-=items[i].first;
            profit+=items[i].second;
        }
        else
        {
            profit = profit + double(items[i].second)/double(items[i].first)*w;
            break;
        }
    }
    
    return profit;
}