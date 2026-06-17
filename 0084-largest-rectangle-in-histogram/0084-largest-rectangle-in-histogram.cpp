class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //nse and pse index for each position
        int n = heights.size();
        vector<int> nse(n, n), pse(n, n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxx = 0;

        for(int i = 0; i < n; i++){
            maxx = max(maxx, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxx;
    }
};