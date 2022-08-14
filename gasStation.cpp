int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]>=B[i])
        {
            int sum1=0;
            int sum2=0;
            int j=i;
            int flag=0;
            while(j<n+i)
            {
                sum1+=A[j%n];
                sum2+=B[j%n];
                if(sum1<sum2)
                {
                    flag=1;
                    break;
                }
                j++;
            }
            if(flag==0)
            return i;
        }
    }
    
    return -1;
}
