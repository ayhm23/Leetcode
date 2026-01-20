class Solution {
public:
    void gen(vector<string> &ans, string s, int open, int close, int n) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            gen(ans, s + "(", open + 1, close, n);
        }

        if (close < open) {
            gen(ans, s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, "", 0, 0, n);
        return ans;
    }
};
