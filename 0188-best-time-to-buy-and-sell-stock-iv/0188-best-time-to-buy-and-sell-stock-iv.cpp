class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //0 and n+1th useslestt states for transaction
        vector<vector<int>> dp(n+1, vector<int>(2*(k+1), 0));
        vector<int> curr (2*(k+1), 0);
        vector<int> next (2*(k+1), 0);
        for(int i = n-1; i >= 0; i--){
            for(int trans = 1; trans <= 2*k; trans++){
                int p = prices[i];
                if(trans%2){
                    //buy
                    curr[trans] = max(-p +next[trans+1], next[trans]);
                }
                else{
                    curr[trans] = max(p + next[trans+1], next[trans]);
                }
            }
            next = curr;
        }
        return next[1];
    }
};