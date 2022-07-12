int Solution::solve(string A) {
    string B = A;
    reverse(A.begin(),A.end());
    
    string s = B + "$" + A;
    vector<int> LPS(s.size(),0);
    int j=0;
    int i=1;
    while(i<s.size())
    {
        if(s[j]==s[i])
        {
            LPS[i]=j+1;
            i++,j++;
        }
        else
        {   
            if(j!=0)
            j = LPS[j-1];
            else
            i++;
        }
    }
    
    return A.size()-LPS[s.size()-1];
}
