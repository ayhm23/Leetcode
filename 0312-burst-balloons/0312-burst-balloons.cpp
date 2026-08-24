class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            balloons[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // length is the interval length between left and right
        for (int length = 2; length <= n + 1; ++length) {
            for (int left = 0; left + length <= n + 1; ++left) {
                int right = left + length;
                for (int i = left + 1; i < right; ++i) {
                    int coins = balloons[left] * balloons[i] * balloons[right];
                    coins += dp[left][i] + dp[i][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};
