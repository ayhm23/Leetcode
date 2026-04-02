class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            int p = prices[i] - mini;
            profit = max(p, profit);
            mini = min(mini, prices[i]);
        }   
        return profit;
    }
};