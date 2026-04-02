class Solution {
public:
    bool DP(string &s, string &p, vector<vector<int>> &dp, int i, int j){
        
        if(i == 0 && j == 0) return true;
        if(j == 0) return false;

        if(i == 0){
            for(int k = 1; k <= j; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = DP(s, p, dp, i-1, j-1);
        }

        if(p[j-1] == '*'){
            return dp[i][j] = (
                DP(s, p, dp, i, j-1) ||   // * → empty
                DP(s, p, dp, i-1, j)     // * → consume char
            );
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return DP(s, p, dp, n, m);
    }
};