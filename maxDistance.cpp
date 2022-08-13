int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<pair<int,int>> arrayWithIndex;
    
    for(int i=0;i<n;i++)
    {
        arrayWithIndex.push_back({A[i],i});
    }
    
   sort(arrayWithIndex.begin(),arrayWithIndex.end());
   
   int maxdiff=0;
   int minind=INT_MAX;
   
   for(int i=0;i<n;i++)
   {
       minind=min(minind,arrayWithIndex[i].second);
       maxdiff = max(maxdiff,arrayWithIndex[i].second-minind);
   }
    
    return maxdiff;
}
