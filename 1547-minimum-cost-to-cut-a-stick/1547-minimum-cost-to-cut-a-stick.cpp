class Solution {
public:
    int DP(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i + 1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int k = i + 1; k < j; k++){
            int ops = (cuts[j] - cuts[i]) 
                    + DP(cuts, i, k, dp)
                    + DP(cuts, k, j, dp);

            mini = min(mini, ops);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int i = cuts.size();
        vector<vector<int>> dp (i, vector<int> (i, -1));

        return DP(cuts, 0, cuts.size() - 1, dp);
    }
};