bool isValid(int ind,vector<int>& inorder, vector<int>& preorder, int lb, int ub)
{
    
}
int Solution::solve(vector<int> &A) {
    set<int> s;
    for(auto elem:A)
    s.insert(elem);
    
    if(s.size()!=A.size()) return false;
    
    int root=INT_MIN;
    stack<int> st;
    for(int i=0;i<A.size();i++)
    {
        while(!st.empty()&&A[i]>st.top())
        {   
            root=st.top();
            st.pop();
        }
        
        if(A[i]<=root)
        return false;
        
        st.push(A[i]);
    }
    
    return true;
}
