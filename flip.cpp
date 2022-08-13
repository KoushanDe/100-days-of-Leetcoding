vector<int> Solution::flip(string A) {
    int i=0,j=0;
    int l=-1,r=-1;
    int count=0;
    int maxcount=0;
    for(;j<A.size();j++)
    {
        if(A[j]=='0')
        {
            count++;
            if(count>maxcount)
            {
                maxcount=count;
                l=i;
                r=j;
            }
        }
        else 
        {
            count--;
        }
        
        if(count<0)
        {
            count=0;
            i=j+1;
        }
    }
    
    if(l==-1)
    return {};
    else
    return {l+1,r+1};
}
