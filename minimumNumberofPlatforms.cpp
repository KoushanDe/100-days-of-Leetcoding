#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> time(2400,0);
    
    for(int i=0;i<n;i++)
    {
        time[at[i]]++;
        time[dt[i]+1]--; //problem specific: if two train has equal dt & at respectivly then 2 platform is reqd here
    }
    int plat=0,maxplat=0;
    for(int i=0;i<2400;i++)
    {
        plat+=time[i];
        if(plat>maxplat)
            maxplat=plat;
    }
    return maxplat;
}