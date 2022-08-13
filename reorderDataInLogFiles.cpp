bool compare(string& s1, string& s2)
{
    int i1 = s1.find("-") + 1;
    int i2 = s2.find("-") + 1;
    string s11=s1.substr(i1);
    string s22=s2.substr(i2);
    if(s11==s22)
    return s1<s2;
    else
    return s11<s22;
}
vector<string> Solution::reorderLogs(vector<string> &A) {
    vector<string> ans;
    vector<int> digs;
    
    for(int i=0;i<A.size();i++)
    {
        int ind = A[i].find("-");
        if(A[i][ind+1]>='a'&&A[i][ind+1]<='z')
        ans.push_back(A[i]);
        else
        digs.push_back(i);
    }
    
    sort(ans.begin(),ans.end(),compare);
    
    for(int i=0;i<digs.size();i++)
    ans.push_back(A[digs[i]]);
    
    return ans;
}
