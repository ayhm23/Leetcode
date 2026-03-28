class Solution {
public: 
    using ll = long long;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        //dp[i][a]... coints seen till ith idx.. amount a can be generated..with dp methods;
        
       
        vector<int> dp (amount + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int a = 0; a <= amount; a++){
                //not take
                ll notTake = dp[a];
                //take
                ll take = 0;
                if(a >= coins[i-1]){
                    take = dp[a - coins[i-1]];
                }
                dp[a] = take + notTake;
            }
        }

        return dp[amount];
    }
};