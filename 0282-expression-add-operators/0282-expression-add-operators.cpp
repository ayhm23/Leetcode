class Solution {
public:
    void dfs(vector<string>& ans, string& num, int target,
             int idx, long long eval, long long prev, string expr) {

        if (idx == num.size()) {
            if (eval == target) ans.push_back(expr);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            // avoid numbers with leading zero
            if (i > idx && num[idx] == '0') break;

            string part = num.substr(idx, i - idx + 1);
            long long curr = stoll(part);

            if (idx == 0) {
                // first number (no operator)
                dfs(ans, num, target, i + 1, curr, curr, part);
            } else {
                dfs(ans, num, target, i + 1, eval + curr, curr, expr + "+" + part);
                dfs(ans, num, target, i + 1, eval - curr, -curr, expr + "-" + part);
                dfs(ans, num, target, i + 1,
                    eval - prev + prev * curr,
                    prev * curr,
                    expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, num, target, 0, 0, 0, "");
        return ans;
    }
};
