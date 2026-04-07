class Solution {
public:
    int DP(vector<int>& nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = 0;
        for(int k = i; k <= j; k++){
            int ops = nums[i-1]*nums[k]*nums[j+1];
            int rest = DP(nums, i, k-1, dp) + DP(nums, k+1, j, dp);
            

            maxi = max(rest + ops , maxi);
        }
        
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        nums.insert(nums.begin(), 1); nums.push_back(1);
        return DP(nums, 1, n, dp);
    }
};