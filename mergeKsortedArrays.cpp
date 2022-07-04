#include<bits/stdc++.h>
using namespace std;
//TWO POINTER MERGING APPROACH
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{    
    if(k==1) return kArrays[0];
    
    vector<int> v1,v2;
    
    v1=kArrays[0];
    
    
    for(int l=1;l<k;l++)
   {    
        v2=kArrays[l];
        vector<int> temp;
        
        int i=0,j=0;
        
        while(i<v1.size()&&j<v2.size())
        {
            if(v1[i]<v2[j])
                temp.push_back(v1[i++]);
            else
                temp.push_back(v2[j++]);
        }
        
        if(i==v1.size()||j==v2.size())
        {    
            while(i<v1.size())
                temp.push_back(v1[i++]);
            while(j<v2.size())
                temp.push_back(v2[j++]);
        }
        
        v1=temp;
    }
    
    return v1;
}

//MINHEAP APPROACH
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    
    for(int i=0;i<k;i++)
        pq.push({kArrays[i][0],i});
    
    vector<int> index(k,0);
    vector<int> ans;
    
    while(!pq.empty())
    {
        int num = pq.top().first;
        int arr = pq.top().second;
        pq.pop();
        
        ans.push_back(num);
        
        if(index[arr]+1<kArrays[arr].size())
        {
            pq.push({kArrays[arr][index[arr]+1],arr});
            index[arr]++;
        }
    }
    
    return ans;
}

