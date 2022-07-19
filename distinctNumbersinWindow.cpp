vector<int> Solution::dNums(vector<int> &A, int B) {
    int count = 0;
    vector<int> distinct;
    map<int,int> freq;
    
    if(B>A.size()) return distinct;
    
    for(int i=0;i<B;i++)
    {
        if(freq[A[i]]==0)
        count++;
        freq[A[i]]++;
    }
    
    distinct.push_back(count);
    
    for(int i=B;i<A.size();i++)
    {
        freq[A[i-B]]--;
        if(freq[A[i-B]]==0) count--;
        
        if(freq[A[i]]==0)
        count++;
        
        freq[A[i]]++;
        distinct.push_back(count);
    }
    
    return distinct;
}
