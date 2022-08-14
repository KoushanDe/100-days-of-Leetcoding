int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int maxtime=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        maxtime=max(maxtime,abs(A[i]-B[i]));
    }
    
    return maxtime;
}
