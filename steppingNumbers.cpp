vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    
    for(int i=A;i<=B;i++)
    {   
        int num = i;
        int prev=-1;
        int dig;
        while(num)
        {
            dig=num%10;
            if(prev!=-1&&abs(dig-prev)!=1)
            break;
            prev=dig;
            num/=10;
        }
        
        if(num==0) ans.push_back(i);
    }
    
    return ans;
}
