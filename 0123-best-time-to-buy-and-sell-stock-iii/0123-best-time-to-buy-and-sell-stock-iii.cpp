class Solution {
public:
    int DP(vector<int>& prices, int i, int buy, vector<vector<int>> &dp){
        //buy can be 1, 2, 3, 4..mod 2..
        //1, 3 -> means can but.. 2, 4.. cant buy

        if(buy > 4 || i == prices.size()) return 0;
        if(dp[i][buy-1] != -1) return dp[i][buy-1];
        int p = prices[i];
        if(buy%2){
            //b == 1 or buy 1 or 3
            return dp[i][buy-1] = max(-p + DP(prices, i + 1, buy+1, dp), DP(prices, i+1, buy, dp));
        }
        else{
            return dp[i][buy-1] = max(p + DP(prices, i+1, buy+1, dp), DP(prices, i+1, buy, dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (6 , 0));
    
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= 4; j++){
                int p = prices[i];
                if(j % 2 == 1){
                    dp[i][j] = max(-p + dp[i+1][j+1], dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(p + dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][1];
    }
};