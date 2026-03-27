class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (target > sum || target < -sum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*sum + 1, 0));

        dp[0][sum] = 1; // sum = 0

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2*sum; j++) {

                int currS = j - sum;

                int plus = 0, minus = 0;

                if (currS - nums[i-1] >= -sum)
                    plus = dp[i-1][(currS - nums[i-1]) + sum];

                if (currS + nums[i-1] <= sum)
                    minus = dp[i-1][(currS + nums[i-1]) + sum];

                dp[i][j] = plus + minus;
            }
        }

        return dp[n][target + sum];
    }
};