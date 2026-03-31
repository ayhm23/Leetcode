class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //need length
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char a = text1[i-1]; char b = text2[j-1];
                if(a == b){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n][m];
    }
};