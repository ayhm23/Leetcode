class Solution {
public:
    vector<vector<int>> dp;

    int rec(int amount, vector<int>& coins, int i) {

        if(amount == 0) return 1;

        if(amount < 0 || i < 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];


        int take = rec(amount - coins[i], coins, i);

        int skip = rec(amount, coins, i-1);


        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1, -1));

        return rec(amount, coins, n-1);
    }
};