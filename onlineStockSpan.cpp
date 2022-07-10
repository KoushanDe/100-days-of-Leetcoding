class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index=0;
    StockSpanner() {
        st.push({INT_MAX,-1});
    }
    
    int next(int price) {
        while(price>=st.top().first)
            st.pop();
        int span = index - st.top().second;
        st.push({price,index});
        index++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */