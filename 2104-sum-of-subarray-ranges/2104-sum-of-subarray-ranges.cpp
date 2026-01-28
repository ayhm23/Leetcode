class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        vector<int> psee(n), nse(n);   // for minimum
        vector<int> pgee(n), nge(n);   // for maximum

        // -------- MINIMUM CONTRIBUTION --------

        // Previous Smaller or Equal
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            psee[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nse[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // -------- MAXIMUM CONTRIBUTION --------

        // Previous Greater or Equal
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            pgee[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nge[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // -------- FINAL ANSWER --------

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long maxCnt = (long long)pgee[i] * nge[i];
            long long minCnt = (long long)psee[i] * nse[i];
            ans += (maxCnt - minCnt) * nums[i];
        }

        return ans;
    }
};
