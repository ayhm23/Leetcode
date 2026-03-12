class Solution {
public:
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, -1);

    //     dp[0] = 1;
    //     dp[1] = 1;

    //     //dp[n] = dp[n-1] + dp[n-2]
    //     for(int i = 2; i <= n; i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }

    //     return dp[n];
    // }

    int climbStairs(int n) {

        int prev1 = 1;
        int prev2 = 1;

        //dp[n] = dp[n-1] + dp[n-2]
        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1; prev1 = curr;
        }

        return prev1;
    }
};