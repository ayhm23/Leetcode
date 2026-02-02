class StockSpanner {
public:
    stack<pair<int,int>> st;  // {price, span}

    StockSpanner() {}

    int next(int price) {
        int count = 1;

        
        while(!st.empty() && st.top().first <= price) {
            count += st.top().second;  // merge spans
            st.pop();
        }

        st.push({price, count});
        return count;
    }
};
