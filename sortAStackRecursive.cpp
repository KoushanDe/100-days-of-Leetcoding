void insert(stack<int>& st, int temp)
{
    if(st.size()==0||temp>st.top())
    {
        st.push(temp);
        return;
    }
    
    int top = st.top();
    st.pop();
    insert(st,temp);
    st.push(top);
}
void sortStack(stack<int> &stack)
{    
    if(stack.size()==1)
        return;
	
    int top = stack.top();
    stack.pop();
    sortStack(stack);
    
    insert(stack,top);
}