class Solution {
public:
    // int numDistinct(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();

    //     vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

    //     // base case
    //     for(int i = 0; i <= n; i++) dp[i][0] = 1;

    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= m; j++){
    //             if(s[i-1] == t[j-1])
    //                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    //             else
    //                 dp[i][j] = dp[i-1][j];
    //         }
    //     }

    //     return dp[n][m];
    // }

    int DP(string& s, string&t, vector<vector<long long>> & dp, int i, int j){
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            dp[i][j] = DP(s, t, dp, i-1, j) + DP(s, t, dp, i-1, j-1);
        }
        else{
            dp[i][j] = DP(s, t, dp, i-1, j);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));

        // base case
        for(int i = 0; i <= n; i++) dp[i][0] = 1; // first col

        return DP(s, t, dp, n, m);
    }
};