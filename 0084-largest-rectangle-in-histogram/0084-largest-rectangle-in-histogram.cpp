class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //need nse pse - next  smaller element and previous smaller element
        int n = heights.size();
        vector<int> pse(n, -1);

        stack<int> st;

        for(int i = 0; i < n; i++){
            int cur = heights[i];
            while(!st.empty() && heights[st.top()] >= cur) st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();

        vector<int> nse(n, n);

        for(int i = n-1; i >= 0; i--){
            int cur = heights[i];
            while(!st.empty() && heights[st.top()] >= cur) st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int cur = width * heights[i];
            ans = max(ans, cur);
        }
        return ans;

    }
};