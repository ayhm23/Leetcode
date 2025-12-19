class Solution {
public:
    string removeOuterParentheses(string s) {
        // '(' = 1 and ')' = -1
        int score = 0;
        string ans;
        for(char c : s){
            int p = (c == '(' ? 1 : -1);
            if(score == 0 || score + p == 0){
                score+=p;
                continue;
            }
            else{
                ans.push_back(c);
            }
            score+=p;
        }
        return ans;
    }
};