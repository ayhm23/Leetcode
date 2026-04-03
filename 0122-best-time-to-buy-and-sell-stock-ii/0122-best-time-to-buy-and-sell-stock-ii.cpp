class Solution {
public:
    
    int DP(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int p = prices[idx];

        if(buy){
            return dp[idx][buy] = max(
                -p + DP(prices, idx+1, 0, dp),
                DP(prices, idx+1, 1, dp)
            );
        }
        else{
            return dp[idx][buy] = max(
                p + DP(prices, idx+1, 1, dp),
                DP(prices, idx+1, 0, dp)
            );
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return DP(prices, 0, 1, dp);  // ✅ only this
    }
};