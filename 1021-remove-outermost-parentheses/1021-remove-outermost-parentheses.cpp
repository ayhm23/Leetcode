class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0; string ans = "";
        for(char c : s){
            int score = (c == '(') ? 1 : -1;
            if (!(cnt + score == 0 || !cnt)) {
                ans += c;
            }
            cnt += score;
        }
        return ans;
    }
};