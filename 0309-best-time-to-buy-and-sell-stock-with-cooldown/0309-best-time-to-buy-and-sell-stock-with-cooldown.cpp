class Solution {
public:
    vector<vector<int>> dp;
    const int NEG = INT_MIN / 2;

    int recursion(vector<int>& prices, int state, int i){
        if (i <= 0) return (state == 1) ? 0 : NEG;   // holding w/ 0 days = impossible
        if (dp[i][state] != INT_MAX) return dp[i][state];
        int p = prices[i-1];
        if (state == 1) { // free / can buy: sell has NO cooldown constraint -> i-1
            return dp[i][state] = max(recursion(prices, 1, i-1),
                                       p + recursion(prices, 0, i-1));
        } else {          // holding / can sell: buying needs the cooldown gap -> i-2
            return dp[i][state] = max(recursion(prices, 0, i-1),
                                      -p + recursion(prices, 1, i-2));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<int>(2, INT_MAX)); // INT_MAX = "not computed" sentinel
        return recursion(prices, 1, n);
    }
};