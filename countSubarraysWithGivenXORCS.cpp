#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0,cnt= 0;
    map<int,int> freq;
    
    for(int i=0;i<arr.size();i++)
    {
        xr=xr^arr[i]; //calculates prefix XOR
        if(xr==x) cnt++; //checks if prefix XOR == x
        cnt += freq[xr^x]; //checks if y = prefXOR ^ x exists in freq, if yes adds its frequency
        freq[xr]++; //increments prefix XOR count in freq map 
    }
    return cnt;
}