class StockSpanner {
public:
    stack<pair<int, int>> st;
    int counter = 1;

    StockSpanner() {

    }
    
    int next(int price) {
        //pge;

        while(!st.empty() && st.top().first <= price) st.pop();

        int ans = (counter - (st.empty() ? 0 : st.top().second));

        st.push({price, counter++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */