class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // get pse and nse and calculate area from the difference in index
        int n = heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        if(n == 1) return heights[0];

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nse[st.top()] = n;
            st.pop();
        }

        
        // loop condition fixed (must include i = 0)
        for(int i = n - 1; i >= 0; i--){   // was: i > 0
            while(!st.empty() && heights[st.top()] > heights[i]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // default PSE should be -1, not 0
        while(!st.empty()){
            pse[st.top()] = -1;          
            st.pop();
        }

        int maxx = 0;
        for(int i = 0; i < n; i++){
            int curr = heights[i] * (nse[i] - pse[i] - 1);
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};
