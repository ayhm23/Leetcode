class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // Step 1: Precompute palindrome table
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) pal[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2) pal[i][j] = true;
                    else pal[i][j] = pal[i+1][j-1];
                }
            }
        }

        // Step 2: 1D DP
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (pal[j+1][i]) {
                        dp[i] = min(dp[i], 1 + dp[j]);
                    }
                }
            }
        }

        return dp[n-1];
    }
};