class MinStack {
public:
    stack<pair<int,int>> st;
    int minm;
    MinStack() {
        minm=INT_MAX;
    }
    
    void push(int val) {
        int topmin = st.empty()?INT_MAX:st.top().second;
        minm = min(topmin,val);
        st.push({val,minm});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */