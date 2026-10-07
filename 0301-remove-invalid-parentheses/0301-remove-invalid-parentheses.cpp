class Solution {
public:
    set<string> ans;
    int mini = INT_MAX;

    void rec(const string &s, int i, string& cur, int cnt){
        if(i == s.length()){
            if(cnt == 0){ //string is valid
                if(s.length() - cur.length() < mini){
                    ans = {cur};
                    mini = s.length() - cur.length();
                }
                else if(s.length() - cur.length() == mini){
                    ans.insert(cur);
                }
            }
            return;
        }
        if(cnt < 0) return;
        char c = s[i];
        if(c != '(' && c != ')'){
            cur.push_back(c);
            rec(s, i+1, cur, cnt);
            cur.pop_back();
        }
        else{
            int p = c == '(' ? 1 : -1;

            rec(s, i+1, cur, cnt); //not take

            cur.push_back(c);
            rec(s, i+1, cur, cnt+p);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        //idea iis recursion backtracking
        string cur = "";
        rec(s, 0, cur, 0);
        return vector<string> (ans.begin(), ans.end());
    }
};