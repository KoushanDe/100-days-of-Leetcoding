int Solution::solve(vector<int> &A, int B) {
        int elem1=0,elem2=0,elem3=0;
        
        for(int i=0;i<A.size();i++)
        {
            if(elem1==0)
            elem1=A[i];
            else if(elem2==0&&A[i]!=elem1)
            elem2=A[i];
            else if(elem3==0&&A[i]!=elem1&&A[i]!=elem2)
            elem3=A[i];
            else if(A[i]!=elem1&&A[i]!=elem2&&A[i]!=elem3)
            return 0;
        }
        
        //cout<<elem1<<" "<<elem2<<" "<<elem3<<endl;
        
        if(elem2==0&&elem3==0)
        return 1;
        
        if(elem3==0)
        return abs(elem1-elem2)==B||abs(elem1-elem2)==2*B;
        
        int maxm = max(max(elem1,elem2),elem3);
        int minm = min(min(elem1,elem2),elem3);
        int mid;
        
        if(elem1!=maxm&&elem1!=minm) mid=elem1;
        else if(elem2!=maxm&&elem2!=minm) mid=elem2;
        else if(elem3!=maxm&&elem3!=minm) mid=elem3;
        
        return (maxm-mid)==B&&(mid-minm)==B;
}
