class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // Step 1: Build monotonic increasing stack
        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Step 2: If removals left, remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: Build result string
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Step 4: Remove leading zeros
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0') idx++;
        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;
    }
};
