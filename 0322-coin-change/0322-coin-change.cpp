class Solution {
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     int count = 0;
    //     if(amount == 0){
    //         return count;
    //     }

    //     sort(coins.begin(), coins.end(), greater<int>());
    //     for(int i = 0; i < coins.size();){
    //         if(coins[i] > amount){
    //             i++;
    //         }
    //         else if(amount == 0){
    //             break;
    //         }
    //         else if(coins[i] <= amount){
    //             count++;
    //             amount-=coins[i];
    //         }
    //     }
    //     return amount == 0 ? count : -1;
    // }

    //dp solution
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int a = 0; a <= amount; a++) {

                // not take
                int notTake = dp[i-1][a];

                // take (stay on same i)
                int take = INF;
                if (a >= coins[i-1]) {
                    take = 1 + dp[i][a - coins[i-1]];
                }

                dp[i][a] = min(take, notTake);
            }
        }

        return dp[n][amount] == INF ? -1 : dp[n][amount];
    }
};