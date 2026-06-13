class Solution {
public:
    vector<string> ans;
    void gen(string curr, int open, int close, int n){
        if(curr.size() == 2 * n){
            ans.push_back(curr); return;
        }   
        if(open < n){
            gen(curr + '(', open + 1, close, n);
        }
        if(close < open){
            gen(curr + ')', open, close+1, n);
        }
        return;    
    }
    vector<string> generateParenthesis(int n) {
        gen("", 0, 0, n);
        return ans;
    }
};