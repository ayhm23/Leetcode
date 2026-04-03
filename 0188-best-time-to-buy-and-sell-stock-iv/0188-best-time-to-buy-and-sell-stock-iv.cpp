class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // optimization: unlimited transactions case
        if(k >= n/2){
            int profit = 0;
            for(int i = 1; i < n; i++){
                if(prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }

        vector<int> next(2*k + 2, 0), curr(2*k + 2, 0);

        for(int i = n-1; i >= 0; i--){
            for(int trans = 1; trans <= 2*k; trans++){
                
                if(trans % 2){ // buy
                    curr[trans] = max(
                        -prices[i] + next[trans+1],
                        next[trans]
                    );
                }
                else{ // sell
                    curr[trans] = max(
                        prices[i] + next[trans+1],
                        next[trans]
                    );
                }
            }
            next = curr;
        }

        return next[1];
    }
};