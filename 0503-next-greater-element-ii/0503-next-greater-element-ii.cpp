class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int num = nums[i % n];
            while (!st.empty() && st.top() <= num)
                st.pop();
            if (i < n)
                res[i] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        return res;
    }
};
