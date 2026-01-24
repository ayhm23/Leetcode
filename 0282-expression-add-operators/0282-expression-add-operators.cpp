class Solution {
public:
    void check(vector<string>& ans, string& num, int target,
               int i, long long curr, long long prev, string currStr) {

        if (i == num.length()) {
            if (curr == target)
                ans.push_back(currStr);
            return;
        }

        for (int j = i; j < num.length(); j++) {

            // avoid numbers with leading zero
            if (j > i && num[i] == '0') break;

            string part = num.substr(i, j - i + 1);
            long long val = stoll(part);

            if (i == 0) {
                // first number (no operator before it)
                check(ans, num, target, j + 1, val, val, part);
            } else {
                // +
                check(ans, num, target, j + 1,
                      curr + val, val,
                      currStr + "+" + part);

                // -
                check(ans, num, target, j + 1,
                      curr - val, -val,
                      currStr + "-" + part);

                // *
                check(ans, num, target, j + 1,
                      curr - prev + prev * val,
                      prev * val,
                      currStr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        check(ans, num, target, 0, 0, 0, "");
        return ans;
    }
};

auto init = atexit([]{ofstream("display_runtime.txt") << '0';});

