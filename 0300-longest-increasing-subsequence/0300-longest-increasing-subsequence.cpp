class Solution {
public:
    int len(vector<int> &nums, int i, int prev, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int notTake = len(nums, i+1, prev, dp);

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + len(nums, i+1, i, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return len(nums, 0, -1, dp);
    }
};