class Solution {
public:
    set<string> mul(set<string>& a, set<string>& b) {
        set<string> res;
        for(auto &x : a)
            for(auto &y : b)
                res.insert(x + y);
        return res;
    }

    set<string> solve(string &s, int &i) {
        set<string> cur, res;

        while(i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> nxt;

            if(s[i] == '{') {
                i++;
                nxt = solve(s, i);
                i++; // skip '}'
            }
            else {
                nxt.insert(string(1, s[i]));
                i++;
            }

            if(cur.empty())
                cur = nxt;
            else
                cur = mul(cur, nxt);
        }

        while(i < s.size() && s[i] == ',') {
            i++; // skip ','

            set<string> nxt = solve(s, i);

            for(auto &x : nxt)
                res.insert(x);
        }

        for(auto &x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};