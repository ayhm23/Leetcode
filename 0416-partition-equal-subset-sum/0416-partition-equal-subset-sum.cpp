class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // main dp
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= target; s++) {

                bool take = false;

                if (nums[i-1] <= s) {
                    take = dp[i-1][s - nums[i-1]];
                }

                bool notTake = dp[i-1][s];

                dp[i][s] = take || notTake;
            }
        }

        return dp[n][target];
    }
};