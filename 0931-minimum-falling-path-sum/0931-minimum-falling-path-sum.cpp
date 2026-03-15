class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0) {
                    dp[i][j] = matrix[i][j]; continue;
                }

                int top = dp[i-1][j];
                int dg = min((j > 0 ? dp[i-1][j-1] : INT_MAX), (j < n-1 ? dp[i-1][j+1] : INT_MAX));

                dp[i][j] = matrix[i][j] + min(top, dg);
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};